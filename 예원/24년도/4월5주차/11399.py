n = int(input())
arr = list(map(int, input().split()))
arr.sort()
num, count = 0,0
for i in arr:
    num +=i
    count+=num 
print(count)