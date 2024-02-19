from collections import deque
def bfs(map, visited, n, m):
    queue = deque([0,0])
    visited[0][0] = True
    dx = [-1, 1, 0,0] #동,서,남,북
    dy = [0,0,1,-1]
    while queue:
        y,x = queue.popleft()
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if 0<=nx <m and 0<=ny<n and maps[ny][nx]:
                if not visited[ny][nx]:
                    visited[ny][nx] = True
                    queue.append((ny, nx))
                    maps[ny][nx] = maps[y][x]+1
    return maps[n-1][m-1]
def solution(maps):
    n,m = len(maps), len(maps[0])
    visited = [[False]*m for _ in range(n)]
    answer = bfs(maps, visited, n, m)
    if answer == 1:
        return -1
    return answer