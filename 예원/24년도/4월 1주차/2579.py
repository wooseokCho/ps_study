n = int(input())
array=[]
for _ in range(n):
    array.append(int(input()))   
d = [0]*300
if n>=1:
    d[0] = array[0]
if n>=2:
    d[1] = array[0]+array[1]
if n>=3:
    d[2] = max(array[0]+array[2], array[1]+array[2])
    for i in range(3,n):
        d[i] = max(d[i-3]+array[i-1]+array[i], d[i-2]+array[i])
print(d[n-1])
