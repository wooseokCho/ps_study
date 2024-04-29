import sys
input = sys.stdin.readline
n=int(input())

arr = [list(map(int, input().split())) for _ in range(n)]
for k in range(n):
    for a in range(n):
        for b in range(n):
            if arr[a][k] and arr[k][b]:
                arr[a][b] = 1
for row in arr:
    print(*row)