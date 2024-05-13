import sys
input=sys.stdin.readline

#상,하,좌,우
dx = [-1,1,0,0]
dy = [0,0,-1,1]
n,m = map(int, input().split())
array = [list(map(int, input().split())) for _ in range(n)]
visited = [[False]*(m) for _ in range(n)]
max_sum = 0

#"ㅜ"를 뺀 나머지
def dfs(x,y,cnt,val):
    global max_sum
    if cnt == 4:
        max_sum = max(max_sum, val)
        return
    else:
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if 0<= nx <n and 0<=ny<m and not visited[nx][ny]:
                visited[nx][ny] = True
                dfs(nx,ny,cnt+1, val+array[nx][ny])
                visited[nx][ny] = False

    
        
#"+"에서 한 획 뺌
def func1(x,y,cnt,val): 
    global max_sum
    valArr = []
    valFin = []
    for i in range(4):
        nx = x+dx[i]
        ny = y+dy[i]
        if 0<= nx <n and 0<=ny<m:
            valArr.append(array[nx][ny])
            val += array[nx][ny]
            cnt+=1
    
    if len(valArr) == 4:
        for i in range(4):
            valFin.append(val - valArr[i])
            max_sum = max(max_sum, valFin[i])
    if len(valArr) == 3:
        max_sum = max(max_sum, val)


for a in range(n):
    for b in range(m):
        visited[a][b] = True        
        dfs(a,b,1,array[a][b])
        visited[a][b]=False
        func1(a,b,0,array[a][b])

print(max_sum)