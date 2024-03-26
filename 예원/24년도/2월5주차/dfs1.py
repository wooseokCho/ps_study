n, m =map(int, input().split())
#2차원 리스트의 맵 정보 입력받기
graph = []
for i in range(n):
    graph.append(list(map(int, input().split())))
#dfs로 특정한 노드를 방문한 뒤에 연결된 모든 노드들도 방문
def dfs(x,y):
    #범위를 벗어나면 False 처리
    if x<=-1 or y<=-1 or x>=n or y>=m:
        return False
    #아직 방문하지 않았다면 방문처리
    if graph[x][y] == 0:
        graph[x][y] =1
        dfs(x-1, y)
        dfs(x, y-1)
        dfs(x+1, y)
        dfs(x, y+1)
        return True
    return False
#모든 위치에 대해 result계산
result = 0
for i in range(n):
    for j in range(m):
        if dfs(i, j) == True:
            result+=1
print(result)

