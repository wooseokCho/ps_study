n = int(input())
graph = []
for i in range(n):
    graph.append(list(map(int, input().split())))
result = []
def sol(x, y, N):
    color = graph[x][y]
    for i in range(x, x+N):
        for j in range(y, y+N):
            if color != graph[i][j]:
                sol(x, y, N//2)
                sol(x, y+N//2, N//2)
                sol(x+N//2, y, N//2)
                sol(x+N//2, y+n//2, N//2)
                return
    if color == 0:
        result.append(0)
    else:
        result.append(1)


sol(0,0,n)
print(result.count(0))
print(result.count(1))
                   
