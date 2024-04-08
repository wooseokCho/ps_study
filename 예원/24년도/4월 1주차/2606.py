n = int(input())
m = int(input())
graph = [[] for _ in range(n+1)]
visited = [0]*(n+1)
for _ in range(m):
    a,b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
result = 0
def dfs(x):
    visited[x] = True
    for i in graph[x]:
        if visited[i] == 0:
            visited[i] = 1
            dfs(i)
dfs(1)
print(sum(visited)-1)