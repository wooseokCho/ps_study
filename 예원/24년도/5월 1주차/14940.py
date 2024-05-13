from collections import deque
n,m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)] 
distance = [[-1 for _ in range(m)] for _ in range(n)] 
for a in range(n):
    for b in range(m):
        if graph[a][b] == 2:
            start_x, start_y = a, b
            distance[a][b] = 0

#상, 하, 좌, 우
dx = [-1,1,0,0]
dy = [0,0,-1,1]
def bfs():
    queue = deque()
    queue.append((start_x,start_y))
    while queue:
        x,y = queue.popleft()
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if 0<=nx<n and 0<=ny<m and distance[nx][ny] == -1:
                if graph[nx][ny] == 1 or graph[nx][ny] == 2:
                    distance[nx][ny] = distance[x][y]+1
                    queue.append((nx, ny))
bfs()


resultArr = []
for i in range(n):
    for j in range(m):
        if graph[i][j] == 0:
            print(0, end = " ")
        else:
            print(distance[i][j], end = " ")
    print()