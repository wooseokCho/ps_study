from collections import deque
import sys
input = sys.stdin.readline
n,m = map(int, input().split())
arr = [list(input()) for _ in range(n)]
visited = [[False]*m for _ in range(n)]
for i in range(n):
    for j in range(m):
        if arr[i][j] == "I":
            start_x, start_y = i, j
            visited[i][j] = True
            break
dx = [-1,1,0,0]
dy = [0,0,-1,1]
def bfs(x,y):
    count = 0
    queue = deque()
    queue.append((x,y))
    visited[x][y] = True
    while queue:
        x,y = queue.popleft()
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if 0<=nx<n and 0<=ny<m and not visited[nx][ny] and arr[nx][ny] != "X":
                visited[nx][ny] = True
                if arr[nx][ny] == "P":
                    count+=1
                queue.append((nx, ny)) 
    return count

ans = bfs(start_x, start_y)
if ans == 0:
    print("TT")
else:
    print(ans)
