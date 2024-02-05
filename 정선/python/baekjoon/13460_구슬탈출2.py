# https://www.acmicpc.net/problem/13460
def move(y, x, dy, dx) :
    cnt = 0
    ny, nx = y, x
    while (mmap[ny+dy][nx+dx] != "#" and mmap[ny][nx] != "O") :
        ny += dy
        nx += dx
        cnt += 1
    return ny, nx, cnt

N, M = map(int, input().split(" "))
mmap = []

for w in range(N) :
    line = input()
    if line.find('R') != -1 :
        ry, rx = w, line.find('R')

    if line.find('B') != -1 :
        by, bx = w, line.find('B')

    if line.find('O') != -1 :
        hy, hx = w, line.find('O')

    mmap.append(list(line))

direct = [[-1, 0], [1, 0], [0, -1], [0, 1]] # '상', '하', '좌', '우'
queue = [[ry, rx, by, bx, 0]] # [direction, r_loc, b_loc]
visited = []

def solve() :
    while len(queue) != 0 :
        ry, rx, by, bx, cnt = queue.pop(0)
        if cnt >= 10 :
            return -1
        
        visited.append([ry, rx, by, bx])
        for d_idx in range(4) :
            dy, dx = direct[d_idx]

            nry, nrx, rcnt = move(ry, rx, dy, dx)
            nby, nbx, bcnt = move(by, bx, dy, dx)

            if nry == nby and nrx == nbx :
                if nry == hy and nrx == hx :
                    continue
                if rcnt > bcnt :
                    nry -= dy
                    nrx -= dx
                else :
                    nby -= dy
                    nbx -= dx

            elif nry == hy and nrx == hx :
                return cnt+1
            
            if [nry, nrx, nby, nbx] not in visited :
                queue.append([nry, nrx, nby, nbx, cnt+1])
    return -1

print(solve())