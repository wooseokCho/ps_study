# https://www.acmicpc.net/problem/12100
# 3
# 2 2 2
# 4 4 4
# 8 8 8

N = int(input())
MAP = []
eMap = [] # empty map
for _ in range(N) :
    MAP.append(list(map(int, input().split(" "))))
    eMap.append([0] * N)


# 상하좌우 방향
# 상하라면
# 위에서부터 차곡차곡 쌓기
# [0, 2, 2] 
# [2, 0, 0]
# [0, 2, 2]
    
# [0][0], [1][0], [2][0]
# [0][1], [1][1]

# 전치 이용해서 사용하면 되지 않나?
# 구현 어렵구만.. 종이에 쓰면서 해보기
def move_and_merge_blocks() :
    idx = 0 # 상, 좌 0 / 하, 우 N-1
    for m in mmap :
        while 0 in m :
            m.remove(0)
        # m 이동한 상태로 한번씩 돌면서 합쳐주기
        nm = []
        for i in range(len(m)-1) :
            if m[i] == m[i+1] :
                nm.append(m[i]*2)
                i = i + 1
            else :
                nm.append(m[i])
                
        while len(nm) == N:
            nm.insert(idx, 0)

# 상이라면
# for x in range(0, N)
#     y_loc = 0
#     for y in range(0, N)
# y_loc += 1
# 하라면
# for x
# y_loc = N-1
# for y in range(N-1, -1, -1)
# y_loc -= 1
# 좌
# for y in range(0, N)
#     x_loc = 0
#     for x in range(0, N)
#         x_loc += 1
# 우
# for y in range(0, N)
#     x_loc = N-1
#     for x in range(N-1, -1, -1) # (0, N)하고 N-x-i하면 되잖아
#         x_loc -= 1


# 구현은 어떻게?
# 상하좌우
# 상일 때, 해당 방향으로 블록들을 모두 이동시킨 후, 상하좌우 인접하는 것들이 있으면 합쳐주면 됨
# 이 때 합쳐진 블록은 다시 합칠 수 없음
# 이동 -> 합치기
# 합칠 때는 이동하려고 하는 쪽의 칸이 먼저 합쳐짐

# 이동은 하나씩 돌면서?
# 그냥 빈칸 모두 제거하고 앞으로 밀어버리는 식으로 구현?
# 그냥 0으로 구성된 맵 하나 만들어서
# 0이 아닌거 다 해당 방향대로 쌓아주도록 구성
# 옮기면서 위에 숫자가 합쳐진다면 합치기
# 제외처리는? 이전에 합쳤으면 True로해서 못합치도록
