INF = 1e9
def floyd(graph, n):
    dist = [[INF]*(n+1) for _ in range(n+1)]
    for i in range(1, n+1):
        dist[i][i] = 0
    for u in range(1,n+1):
        for v in graph[u]:
            dist[u][v] = 1
            dist[v][u] = 1
    for k in range(1, n+1):
        for a in range(1,n+1):
            for b in range(1, n+1):
                dist[a][b] = min(dist[a][b], dist[a][k]+dist[k][b])
    return dist
def kevin_bacon(dist, n):
    min_kevin_bacon = INF
    person = 0
    for i in range(1, n+1):
        kevin_bacon =sum(dist[i][j] for j in range(1, n+1))
        if kevin_bacon < min_kevin_bacon:
            min_kevin_bacon = kevin_bacon
            person = i
    return person

n,m = map(int, input().split())
graph = [[] for _ in range (n+1)]
for _ in range(m):
    a,b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
distances = floyd(graph, n)
result = kevin_bacon(distances, n)
print(result)
