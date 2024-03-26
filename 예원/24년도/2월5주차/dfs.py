n, m = map(int, input().split())
graph = []
for _ in range(n):
    graph.append(list(map(int, input().split())))
def dfs(x, y):
    #주어진 범위를 벗어나는 경우 즉시
    if x<= -1  or y <= -1 or x>= n or y >=m:
        return False
    #현재 노드를 아직 방문하지 않았다면
    if graph[x][y] == 0:
        #해당 노드를 방문처리
        graph[x][y] =1
        #상,하, 좌, 우의 위치도 모두 재귀적으로 호출
        dfs(x-1,y)
        dfs(x, y-1)
        dfs(x+1,y)
        dfs(x, y+1)
        return True
    return False
#모든 노드(위치)에 대하여 음료수 채우기
result = 0
for i in range(n):
    for j in range(m):
        if dfs(i,j) == True:
            result +=1
print(result)
    
