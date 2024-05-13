
import sys
input = sys.stdin.readline
n=int(input())
arr = [i**2 for i in range (int(n**0.5)+1)]
arr.sort(reverse=True)
dp = [float('inf')]*(n+1)
dp[0] = 0
res = n
for i in arr:
    for j in range(i, n+1):
        dp[j] = min(dp[j], dp[j-i]+1)
print(dp[n])

