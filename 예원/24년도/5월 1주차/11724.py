import sys
from collections import deque
input = sys.stdin.readline
n,m = map(int, input().split())
visited = [False] *(n+1)
graph = [[] for _ in range(n+1)]
queue = deque()
for _ in range(m):
    u,v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
count = 0
def bfs(start):
    queue = deque([start])
    visited[start] = True
    
    while queue:
        node = queue.popleft()
        for neighbor in graph[node]:
            if not visited[neighbor]:
                queue.append(neighbor)
                visited[neighbor] = True

for i in range(1,n+1):
    if not visited[i]:
        bfs(i)
        count+=1
print(count)


