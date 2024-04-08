n=int(input())
m=int(input())
if m == 0:
    blocks=[]
else:
    blocks = list(map(int, input().split()))
mimimum = abs(100-n)
for i in range(99999):
    num = str(i)
    for j in num:
        if int(j) in blocks: #포함되어 있으면
            break
        else:
            minimum = min(mimimum, abs(n-i)+len(num))
print(minimum)