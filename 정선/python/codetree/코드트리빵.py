from collections import deque
# 입력
N, M = map(int, input().split(" "))
basecamps = []
mmap_status = [[True] * N for _ in range(N)]  # REVIEW : [[True] * N] * N으로 쓰면 soft copy되서 한 값 바뀌면 나머지도 다 같이 바뀌는거 주의
mmap_length = [[0] * N for _ in range(N)]
store = []
person_status = [-1] * M # -1 : 대기중, 0 : 이동중, 1 : 도착
persons = [[-1, -1] for _ in range(M)] # -1, -1 좌표로 모두 초기화, REVIEW : 마찬가지로 class list의 * N도 안됨..

for i in range(N) :
    tmp = list(map(int, input().split()))
    for j, v in enumerate(tmp) :
        if v == 1 :
            basecamps.append([i, j]) # 베이스캠프 좌표 저장
for i in range(M):
    ll = input().split()
    # print(i, ll)
    store.append(list(map(int, ll)))
for i, s in enumerate(store) :
    for j, ss in enumerate(s) :
        store[i][j] -= 1

def check_inside_map(y, x) :
    if 0<=y<N and 0<=x<N :
        return True
    return False

# map으로 새롭게 만들어서 dfs 내용 저장하는 방법으로 수정하기...?
# 아마 tmp_routes에서 메모리 초과 나는거 같음 -> 이걸 맵으로 바꾸면 됨...좀만 쉬고 바꾸고 해설하고 도서관 가자..
visited = [[[False] for _ in range(N)] for _ in range(N)]
step = [[[0] for _ in range(N)] for _ in range(N)]
directions = [[-1, 0], [0, -1], [0, 1], [1, 0]]  # 상좌우하 우선순위
def get_shortest_routes(p1, p2, cutoff=N*N) :
    y1, x1 = p1 # 시작 위치
    y2, x2 = p2 # 도착 목표
    # visited, step 값을 전부 초기화합니다.
    for i in range(N):
        for j in range(N):
            visited[i][j] = False
            step[i][j] = 0
    routes = deque([[y1, x1]])
    visited[y1][x1] = True

    # 돌면서 get_shortest 다시 실행하면서 list에 추가하기, 근데 끝까지 가자나 dfs하면...bfs로 해야좋은거아냐? -> 리스트 뒤에 넣고 계속 뽑으면서 해주기
    while len(routes) > 0 :
        tmp_routes = routes.popleft() # 맨 앞에 루트 pop
        ny, nx = tmp_routes
        step_n = step[ny][nx]
        if step_n > cutoff: # 원하는 것보다 크면 return 해주기
            return cutoff+1
        for (dy, dx) in directions : # 상좌우하 우선순위대로 방문
            ty, tx = ny + dy, nx + dx
            if check_inside_map(ty, tx) :
                if not visited[ty][tx] and mmap_status[ty][tx]:  # 지금까지 방문한 위치 제외
                    visited[ty][tx] = True
                    step[ty][tx] = step_n + 1
                    routes.append([ty, tx])
                if [ty, tx] == [y2, x2]:  # 도착한다면!
                    return step_n + 1
    return N*N
def b_p(s) : return f"\033[045m{s}"
def b_r(s) : return f"\033[041m{s}"
def print_mmap(mmap, p, s): # 사람 위치 color로 지정, basecamp 위치 bc, 이동 불가능 영역 br
    for i, m in enumerate(mmap) :
        for j, mm in enumerate(m) :
            tmp = mm
            if [i, j] == p:
                tmp = b_p(tmp)
            if [i, j] == s :
                tmp = b_r(tmp)
            print(f"{tmp}\033[0m ", end="")
        print()
    print()
# 시간초과) 길 계속 계산 안해주기 위해서 routes 저장하고 그 의외의 것들 제외해주기
t = 0
# before_route = {i:[] for i in range(M)}
while min(person_status) < 1 : # 모두 다 도착하면 while stop
    # print(person_status)
    mmap_update = [] # False로 설정할 좌표들
    for i, p in enumerate(persons) :
        sy, sx = store[i][0], store[i][1]  # 의미 없음 편하게 쓰려고, store
        if person_status[i] == 0 :
            get_shortest_routes(store[i], p)  # 최단거리 구해서 1칸 이동
            tmp_list = []
            for di, (dy, dx) in enumerate(directions) :
                ty, tx = p[0] + dy, p[1] + dx
                if check_inside_map(ty, tx) and visited[ty][tx] :
                    tmp_list.append([di, step[ty][tx], ty, tx])
            tmp_list.sort(key=lambda x :(x[1], x[0]))
            persons[i] = tmp_list[0][2:] # 1칸 이동, route에서 시작 지점말고 다른데로
            if persons[i] == [sy, sx] : # 편의점 도착 시, mmap 이동 X으로 설정(그 이후에 이동 X), 사람 status False로 설정
                mmap_update.append([sy, sx])
                person_status[i] = 1 # 사람 도착!

    # LATER) 사람들 이동 완료 후, mmap_status 값들 False로 변경
    for (y, x) in mmap_update :
        mmap_status[y][x] = False

    # 3번 작동
    if t < len(store) : # t가 사람 총 개수보다 커지면 X, store 사람의 목표 편의점
        min_l = N*N
        tmp_route = []
        for i, bc in enumerate(basecamps) : # 베이스캠프와 편의점 사이 최단 거리 계산
            l = get_shortest_routes(bc, store[t], min_l)
            if min_l > l :
                min_l = l
                tmp_route = [[bc[0], bc[1], i]]
            elif min_l == l :
                tmp_route.append([bc[0], bc[1], i]) # 중복된거 나중에 정렬해주려고
        tmp_route.sort(key=lambda x:(x[0], x[1])) # 행, 렬 우선순위대로 정렬
        b_idx = tmp_route[0][-1] # bc 정해짐
        by, bx = basecamps[b_idx]
        mmap_status[by][bx] = False # mmap 이동 X으로 설정,
        basecamps.pop(b_idx) # 베이스캠프 삭제

        person_status[t] = 0  # 사람 이동 상태
        persons[t] = [by, bx] # 사람 위치 베이스캠프로 이동

    t += 1

print(t)