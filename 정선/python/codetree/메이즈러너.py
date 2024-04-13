# 입력)
# N, M, K
# NxN 미로 정보) 0, (1-9) 벽
# M 참가자 좌표) 초기에는 빈칸에만 존재
# 출구 좌표 -> 빈칸...

# 출력) 모든 참가자들의 이동 거리 합과 출구 좌표를 출력
class Point :
    def __init__(self, r, c):
        self.r = r-1
        self.c = c-1

# 입력 받으면서 -1해서 범위 (0, N-1)로 변경
# 입력 받기 ################################################
N, M, K = map(int, input().split(" "))
mmap = []
persons = []
person_status = [True] * M
total_move = 0
for _ in range(N) :
    mmap.append(list(map(int, input().split(" "))))
for _ in range(M) :
    r, c = map(int, input().split(" "))
    persons.append(Point(r, c))
r, c = map(int, input().split(" "))
exit_p = Point(r, c)
#######################################################
def get_distance(r, c) :
    return(abs(exit_p.r-r)+abs(exit_p.c-c))

def check_out_mmap(r, c) :
    if (0 <= r < N) and (0 <= c < N) :
        return True
    return False

def persons_move() :
    # 모든 참가자 이동 - 벽 없는 곳, 가까워지는 곳, 우선순위 상하, 중첩 가능, 이동 횟수 +1, 출구 이동 시 탈출
    global total_move
    directions = [[-1, 0], [1, 0], [0, -1], [0, 1]] # 우선순위 상하
    for i, p in enumerate(persons) :
        if person_status[i] :
            od = get_distance(p.r, p.c) # 이동 전 distance 계산, original_distance : od
            for drt in directions :
                dr, dc = drt
                nr, nc = p.r + dr, p.c + dc
                if check_out_mmap(nr, nc) and mmap[nr][nc] == 0: # 맵을 나가지 않고, 벽이 없으면
                    if od > get_distance(nr, nc) : # 새롭게 얻은 거리가 더 작으면
                        persons[i].r, persons[i].c = nr, nc # 사람 이동
                        total_move += 1
                        break #  DBG) 새롭게 얻은 거리가 더 작으면? 무조건 1차이 아님? 틀리면 break 빼기
            if [persons[i].r, persons[i].c] == [exit_p.r, exit_p.c] : # 출구 이동 시 탈출, REVIEW : class 비교 꺼내서 해야됨 바로 X
                person_status[i] = False

# 정사각형을 어떻게 잡을지
# 같은 사람을 포함하는 정사각형이 어려개 있을 수 있음
# 크기 먼저..., r,c 범위
# DBG) 맵 범위? 상관 있음 - 사람이 오른쪽 하단에? 상관 없나..? 우선 해보고 틀리면 생각
# mmap slicing할 떄 범위 [min_r, max_r+1] 주의
def search_rectangle() :
    er, ec = exit_p.r, exit_p.c
    rectangles = [] # [l, r, c]로 저장
    dlist = []
    for i, p in enumerate(persons) :
        if person_status[i] :
            dr, dc = p.r - er, p.c - ec # P - E
            l = max([abs(dr), abs(dc)]) # 정사각형 길이(3이면 2가 저장됨에 유의)
            # p에서 좌상단 할 수 있는 케이스 4개 확인
            # [0, 0], [0, l], [l, 0], [0, -l], [-l, 0],  # REVIEW : 범위 제대로
            for dlr in range(-l, l+1) :
                for dlc in range(-l, l+1) :
                        # dlr, dlc = dl # 좌상단 좌표 찾기 위해서...
                        tr, tc = er + dlr, ec + dlc # 출구 기준 좌상단 tr, tc
                        if check_out_mmap(tr, tc) and tr <= p.r <= tr + l and tc <= p.c <= tc + l : # 범위 내 사람이 있으면
                            rectangles.append([l, tr, tc])
                        tr, tc = p.r + dlr, p.c + dlc  # 사람 기준 좌상단 tr, tc
                        if check_out_mmap(tr, tc) and tr <= er <= tr + l and tc <= ec <= tc + l:  # 범위 내 사람이 있으면
                            rectangles.append([l, tr, tc])
    # 최종 sort
    rectangles.sort(key=lambda x : (x[0], x[1], x[2])) # 길이 작은 순, r, c 좌표 작은 우선순위
    return rectangles[0]

def check_inside_rect(rr, rc, rl, r, c) :
    if rr <= r <= rr + rl and rc <= c <= rc + rl:
        return True
    return False
def rotate_rectangle(rl, rr, rc) :
    rotated_infos = [] # 회전된 r, c, value 순으로 저장
    # 맵 회전 정보 저장
    for tr, line in enumerate(mmap) :
        for tc, v in enumerate(line) :
            if check_inside_rect(rr, rc, rl, tr, tc) :
            # if rr <= tr <= rr + rl and rc <= tc <= rc + rl :
                rotated_infos.append([tc - rc + rr, rl - (tr - rr) + rc, max(v-1, 0)]) # shift
    if DBG :
        print(f"ROTATED ({rr}, {rc}), size {rl}")
        # print("rotated_infos")
        # for ri in rotated_infos :
        #     print(ri)
    # 저장된 회전 정보 맵에 써주기
    for info in rotated_infos :
        r, c, v = info
        mmap[r][c] = v
    # exit, person 회전
    for i, p in enumerate(persons) :
        if person_status[i] :
            if check_inside_rect(rr, rc, rl, p.r, p.c) :
                persons[i].r, persons[i].c = p.c - rc + rr, rl - (p.r - rr) + rc # DBG) person[i]말고 p.c = 없는지, 이렇게 해도 되는지 확인하기
    exit_p.r, exit_p.c = exit_p.c - rc + rr, rl - (exit_p.r - rr) + rc


def print_mmap() :
    print(" ", end="")
    for i in range(N) :
        print(change_color_y(f" {i}"), end="")
    print()
    for i, m in enumerate(mmap) :
        print(change_color_y(f"{i} "), end="")
        ptr_str = ''
        for j, mm in enumerate(m) :
            flag = True
            if [exit_p.r, exit_p.c] == [i, j] :
                ptr_str += change_color_b(f"{mm}") + " "
                flag = False
            for pi, p in enumerate(persons):
                if person_status[pi]:
                    if [p.r, p.c] == [i, j] :
                        ptr_str += change_bg(f"{mm}") + " "
                        flag = False
                        break
            if flag :
                ptr_str += f"{mm} "
        print(ptr_str)

def change_color_y(s) :
    return '\033[31m' + str(s) + '\033[0m'
def change_color_b(s) :
    return '\033[34m' + str(s) + '\033[0m'
def change_bg(s) :
    return '\033[43m' + str(s) + '\033[0m'

bm = 0
DBG = False
for k in range(K) : # K번 실행
    if DBG :
        print(f"\n\n!! {k+1}초")
        print("before rot")
        print_mmap()
    persons_move()
    if DBG :
        print(f"people move {total_move-bm}")
        print_mmap()

    if not max(person_status) :
        if DBG : print("NO PP")
        break

    # 회전할 정사각형 서치 - 사람 한 명이라도 포함해야함, 크기 작은 순, 좌상단 r, c 작은 순 우선
    rl, rr, rc = search_rectangle() # rectangle, 이때 길이 3이면 rl에는 2가 저장
    # 정사각형 회전 - 출구, 포함된 사람, 벽 모두 회전 => 시계 방향 회전
    rotate_rectangle(rl, rr, rc) # 시계 방향 회전을 어떻게 구현(C, N-R)
    if DBG:
        bm = total_move
        print(f"{k+1} after rot")
        print_mmap()
    # 사람들 없으면 break

print(total_move)
print(exit_p.r+1, exit_p.c+1)