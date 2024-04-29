import sys
input = sys.stdin.readline
n,m = map(int, input().split())
arr = list(map(int, input().split()))
sum = []
val,sum_val = 0, 0
for i in arr:
    sum_val += i
    sum.append(sum_val)
for i in range(m):
    start, end = map(int, input().split())
    if start <2:
        print(sum[end-1])
    else:
        print(sum[end-1] - sum[start-2])
