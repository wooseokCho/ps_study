N,K=map(int, input().split())
a=1
arr=[]
for a in range(1,N+1):
    if N%a==0:
        arr.append(a)
if len(arr) >=K:
    print(arr[K-1])
else: print(0)

