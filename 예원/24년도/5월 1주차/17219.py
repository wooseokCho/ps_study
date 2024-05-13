import sys
input = sys.stdin.readline
n,m = map(int, input().split())
dict = {}
for _ in range(n):
    k, v = input().split()
    dict[k] = v
for _ in range(m):
    search = input().rstrip()
    print(dict[search])
