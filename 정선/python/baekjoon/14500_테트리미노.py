# https://www.acmicpc.net/problem/14500
# 하나만 놔서 하는건 껌이지

# 블록 종류 별로 만드는거, 회전, 대칭 구현하기

# 우선 shift 시키면서 최대값 찾는거 어떤 방법으로 할건지 생각
# 구현을 어떻게 할 것인지

# 2시까지 정리해서 풀기
# 기준점을 두고, 거기서 +- 쉬프트해서 도형 위치를 쓰기
# 예를 들어 [0, 0] [1, 0] [2, 0], [2, 1]
# 회전은 [x, y] -> [y, n-x] 이 식이었나 시켜서, shift 시키면 되지, 회전하면 정렬이 필요함(0, 0)으로 맞추기 위해서 어짜치 shift할거면 n은 나중에 해줘도 되잖아
# 종류별로 싹 돌면서 max 값 저장해서 print하면 됨

tets = [[[0, 0], [0, 1], [0, 2], [0, 3]], [[0, 0], [0, 1], [1, 0], [1, 1]], [[0, 0], [1, 0], [2, 0], [2, 1]],
             [[0, 0], [1, 0], [1, 1], [2, 1]], [[0,0], [0, 1], [0, 2], [1, 1]]]

def rotate_tet(tet) :
    result_tet = [tet]
    shiftted_rotated_tet = tet

    for _ in range(4) : # rotate 4 times
        min_x, min_y = 10, 10

        rotated_tet= []
        for polio in shiftted_rotated_tet :
            y, x = polio
            rotated_tet.append([x, -y])
            min_y = x if min_y > x else min_y
            min_x = -y if min_x > -y else min_x
        
        shiftted_rotated_tet = []
        for rt in rotated_tet :
            shiftted_rotated_tet.append([rt[0]-min_y, rt[1]-min_x])
        shiftted_rotated_tet.sort(key=lambda x :(x[0], x[1]))

        if shiftted_rotated_tet not in result_tet :
            result_tet.append(shiftted_rotated_tet)
    return result_tet

    # 반전 하나 라인만 -로 수정
def flip_n_rotate_tet(tet) :
    result_tet = rotate_tet(tet)

    flip_tet = []
    min_x = 10

    for p in tet :
        flip_tet.append([p[0], -p[1]])
        min_x = -p[1] if min_x > -p[1] else min_x

    shifted_flip_tet = []
    for fp in flip_tet :
        shifted_flip_tet.append([fp[0], fp[1]-min_x])
    shifted_flip_tet.sort(key=lambda x : (x[0],x[1]))

    if shifted_flip_tet not in result_tet :
        result_tet.extend(rotate_tet(shifted_flip_tet))

    return result_tet

def caculate_score(y, x) :
    max_score = 0
    # print_flag = False
    # # if y == 0 and x == 4 :
    # #     print_flag = True

    for tet in all_tets :
        # if print_flag :
        #     print(tet)
        score = 0
        for p in tet :
            ny = y + p[0]
            nx = x + p[1]
            if not ((0 <= ny < N) and (0 <= nx < M)) :
                score = 0
                break
            score += mmap[ny][nx]
        # if print_flag :
        #     print(score)
        #     print()
        if max_score < score :
            max_score = score
            
    return max_score

all_tets = []
for tet in tets:
    # print(tet)
    flip_rot_tets = flip_n_rotate_tet(tet)
    # print("rot")
    # for r in flip_rot_tets :
    #     print(r)
    # print()
    all_tets.extend(flip_rot_tets)

# print(len(all_tets))

N, M = map(int, input().split(" "))
mmap = []
for _ in range(N) :
    mmap.append(list(map(int, input().split(" "))))

result = 0
for yi in range(N) :
    for xi in range(M) :
        score = caculate_score(yi, xi)
        if result < score :
            result = score

print(result)
