from collections import deque
dx = [-1,-1,0]
dy = [-1,0,-1]
dp = [[0]*m for _ in range(n)]
for x in range(n):
    for y in range(m):
        temp = [0]
        for i in range(3):
            nx = x+dx[i]
            ny = y+dy[i]
            if 0<=nx<n and 0<=ny<m:
                temp.append(dp[nx][ny])
        dp[x][y] = max(temp)