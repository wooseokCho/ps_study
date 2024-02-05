n = int(input())
Arr = list(map(int, input().split()))
sum = 0
maxNum = max(Arr)
for i in Arr:
  i = i / maxNum * 100
  sum += i

print(sum / n)