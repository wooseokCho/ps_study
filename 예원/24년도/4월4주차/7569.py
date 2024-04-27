import sys
from collections import deque
input = sys.stdin.readline
m,n,h = map(int, input().split())
matrix = [[list(map(int, input().split())) for _ in range(n)] for _ in range(h)]

#상,하,좌,우,아래, 위
dx = [-1,1,0,0,0,0]
dy = [0,0,-1,1,0,0]
dz = [0,0,0,0,-1,1]
queue = deque()

def bfs():
    while queue:
        z, x, y = queue.popleft()
        
        for i in range(6):
            nx = x+dx[i]
            ny = y+dy[i]
            nz = z+dz[i]
            if 0<=nx<n and 0<=ny<m and 0<=nz<h:
                if matrix[nz][nx][ny] == 0:
                    queue.append((nz, nx, ny))
                    matrix[nz][nx][ny] = matrix[z][x][y]+1

for a in range(h):
    for b in range(n):
        for c in range(m):
            if matrix[a][b][c] ==1:
                queue.append((a,b,c))
bfs()

not_complete = False
day = 0
for i in range(h):
    for j in range(n):
        for k in range(m):
            if matrix[i][j][k] == 0:
                not_complete  = True
            day = max(day, matrix[i][j][k])
if not_complete:
    print(-1)
else:
    print(day-1)


        