import sys
from collections import deque
input = sys.stdin.readline

m,n = map(int, input().split())

array = [list(map(int, input().split())) for _ in range(n)]
#상하좌우
dx = [-1,1,0,0]
dy = [0,0,-1,1]
queue = deque()
def bfs():
    while queue:
        x,y = queue.popleft()
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if 0<=nx<n and 0<=ny<m:
                if array[nx][ny] == 0:
                    array[nx][ny] = array[x][y]+1
                    queue.append((nx,ny))
for a in range(n):
    for b in range(m):
        if array[a][b] == 1:
            queue.append((a,b))
bfs()
not_complete = False
day = 0
for i in range(n):
    for j in range(m):
            if array[i][j] == 0:
                not_complete  = True
            day = max(day, array[i][j])
if not_complete:
    print(-1)
else:
    print(day-1)