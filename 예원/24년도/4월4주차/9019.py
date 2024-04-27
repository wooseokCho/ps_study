import sys
from collections import deque
input = sys.stdin.readline
T=int(input())

for _ in range(T):
    A,B = map(int, input().split())
    visited = [False for i in range(10001)]
    queue = deque()
    queue.append([A,""])
    visited[A] = True

    while queue:
        num, command = queue.popleft()
        if num == B:
            print(command)
            break
        d = num * 2 % 10000
        if not visited[d]:
            visited[d] = True
            queue.append([d, command+"D"])

        s = (num-1)%10000
        if not visited[s]:
            visited[s] = True
            queue.append([s, command+"S"])
        l = num //1000+(num%1000)*10
        if not visited[l]:
            visited[l] = True
            queue.append([l,command+"L"])
        r = num//10 +(num%10)*1000
        if not visited[r]:
            visited[r] = True
            queue.append([r, command+"R"])
