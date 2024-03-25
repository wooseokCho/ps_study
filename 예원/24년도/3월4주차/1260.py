from collections import deque

def dfs(graph, start, visited1):
    visited1[start] =True
    print(start, end=" ")
    for i in graph[start]:
        if not visited1[i]:
            dfs(graph, i, visited1)

def bfs(graph, start, visited2):
    queue = deque([start])
    visited2[start] = True
    while queue:
        num = queue.popleft()
        print(num, end=" ")
        for i in graph[num]:
            if not visited2[i]:
                queue.append(i)
                visited2[i] = True

n,m,v = map(int, input().split()) #정점의 개수, 간선의 개수, 시작정점
graph = [[] for _ in range(n+1)]
for _ in range(m):
    a,b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
visited1 = [False]*(n+1)
visited2 = [False]*(n+1)
for i in range(1, n+1):
    graph[i].sort()
dfs(graph, v, visited1)
print()
bfs(graph, v, visited2)
