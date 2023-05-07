import sys

n, m = map(int, sys.stdin.readline().split())
k = int(sys.stdin.readline())

now = 1
apple_lst = []
answer = 0

for _ in range(k):
    apple_lst.append(int(sys.stdin.readline()))
    
for a in apple_lst:
    if now <= a and now + (m-1) >= a:
        pass
    elif now > a :
        answer += abs(a - now)
        now = a
    else:
        answer += a - (m-1) - now
        now = a - (m-1)
        
print(answer)
