n,k = map(int, input().split())
print(k)
type =[]
count = 0
for i in range(n):
    type.append(int(input()))
type.sort(reverse=True)
print(type)
for i in type:
    if i <= k:
        count+=k//i
        k%=i
    else:
        continue
print(count)