import sys
input= sys.stdin.readline
n = int(input())
arr = list(map(int, input().split()))
arr1 = sorted(set(arr))
index_map = {num: idx for idx, num in enumerate(arr1)}
for num in arr:
    print(index_map[num], end = " ")