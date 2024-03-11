INF = int(1e9)
n,m = map(int, input().split())
graph = [[INF]*(n+1) for i in range(n+1)]

for a in range(n+1):
    for b in range(n+1):
        if a == b:
            graph[a][b] = 0

for i in range(m):
    x, y = map(int, input().split())
    graph[x][y] = 1
    graph[y][x] = 1

x,k = map(int, input().split())

for k in range(n+1):
    for a in range(n+1):
        for b in range(n+1):
            graph[a][b] = graph[a][k]+graph[k][b]

distance = graph[1][k]+graph[k][x]

if distance>=1e9:
    print("-1")
else:
    print(distance)