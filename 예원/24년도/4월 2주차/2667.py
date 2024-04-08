def dfs(x, y):   
    if x<0 or y<0 or x>=n or y>=n:
        return False
    if array[x][y] == 1:
        count=1
        array[x][y] = 0
        count+=dfs(x-1,y)
        count+=dfs(x+1,y)
        count+=dfs(x,y-1)
        count+=dfs(x,y+1)
        return count
    return 0
n = int(input())
array = []
count = 0
val = []
result = 0
for _ in range(n):
    array.append(list(map(int,input())))
for i in range(n):
    for j in range(n):
        if array[i][j] == 1:
            result+=1
            val.append(dfs(i,j))
val.sort()
print(result)
for i in val:
    print(i)

