import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)
n,m, start = map(int, input().split())
graph = [[] for i in range(n+1)]
distance = [INF]*(n+1)

for _ in range(m):
    x,y,z = map(int, input().split())
    graph[x].append((y,z))

def dijkstra(start):
    q = []
    heapq.heappush(q,(0, start))
    distance[start] = 0
    while q: #큐가 비어있지 않다면
        #가장 최단거리가 짧은 노드에 대한 정보 꺼내기
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        #현재 노드와 연결된 "인접한 노드"들 확인
        for i in graph[now]:
            cost = dist + i[1]
            #현재 노드를 거쳐서 가는 경우가 다른 노드로 이동하는 거리보다 더 짧은 경우
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q,(cost, i[0]))
dijkstra(start)
count = 0
max_distance = 0
for d in distance:
    if d!= 1e9: 
        count+=1
        max_distance = max(max_distance, d)
#시작노드는 제외
print(count-1, max_distance)


