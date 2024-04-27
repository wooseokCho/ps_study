t=int(input())
for _ in range(t):
    cloth ={}
    n=int(input())
    result = 1
    for i in range(n):
        name, cate = input().split()
        if cate not in cloth:
            cloth[cate]=1
        else:
            cloth[cate]+=1
    for i in cloth:
        result*=(cloth[i]+1)
    print(result-1)