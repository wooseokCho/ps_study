
# 빈칸이 없으면 후진, 벽에 부딪히면 작동 끝
# 있으면 반시계로 90도 회전 후 앞이 청소되지 않았으면 전진
# d : 0 상, 1 우, 2 하, 3 좌 (반시계 90도 회전 -> -1 % 4)
# 벽이랑 청소되지 않은거랑 다름, 청소된건 2로 나타내기

N, M = map(int, input().split())
r, c, d = map(int, input().split()) # r이 c, c가 r
mmap = []
for _ in range(N) :
    mmap.append(list(map(int, input().split())))

directions = [[-1, 0], [0, 1], [1, 0], [0, -1]] # 상, 우, 하, 좌
result = 0

while (0 <= r < N and 0 <= c < M) : # 벽에 부딪히지 않은 경우
    empty_flag = False
    if mmap[r][c] == 0 :
        mmap[r][c] = 2
        result += 1

    for dr, dc in directions :
        if mmap[r+dr][c+dc] == 0 :
            empty_flag = True
            break

    if empty_flag :
        d = (d-1) % 4
        dr, dc = directions[d]
        if mmap[r+dr][c+dc] == 0 :
            r+=dr
            c+=dc
    else :
        dr, dc = directions[d]
        r-=dr
        c-=dc
        if mmap[r][c] == 1 :
            break

print(result)


