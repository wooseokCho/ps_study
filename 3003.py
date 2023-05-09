chess = list(map(int, input().split()))
data=[1,1,2,2,2,8]
list=[]
for i in range(len(chess)):
    list.append(0)
    list[i] = data[i]-chess[i]
for m in list:
    print(m, end=" ")