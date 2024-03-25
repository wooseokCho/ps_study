from collections import deque
T = int(input())
#상,하,좌,우
dx = [-1,1,0,0]
dy = [0,0,-1,1]

def bfs(x, y):
    queue = [(x,y)]
    graph[x][y] = 0
    
    while queue:
        x,y = queue.pop(0)
    
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if 0 > nx or nx>= M or ny<0 or ny>= N:
                continue
            if graph[nx][ny] == 1:
                graph[nx][ny] = 0
                queue.append((nx, ny))


for _ in range(T):
    count = 0
    M, N, K = map(int, input().split())  # 가로(M), 세로(N)
    graph = [[0] * N for _ in range(M)]
    for _ in range(K):
        a, b = map(int, input().split())  # 가로, 세로
        graph[a][b] = 1
    for i in range(M):
        for j in range(N):
            if graph[i][j] == 1:
                bfs(i,j)
                count += 1
    print(count)
