import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
for i in range(n):
    a = input().strip()
    m = int(input())
    flag = 1
    arr = input().strip()
    dq = deque(arr[1:-1].split(","))
    if m == 0:
        dq = deque()
    rev_count = 0
    for i in range(len(a)):
        if a[i] == "R":
            rev_count+=1
        elif a[i] == "D":
            if len(dq) == 0:
                print("error")
                flag = 0
                break
            else:
                if  rev_count%2 == 0:
                    dq.popleft()
                else:
                    dq.pop()
    if flag == 0: #에러가 난 경우 다음으로
        continue
    else:
        if rev_count%2 == 0:
            print("["+",".join(dq)+"]")
        else:
            dq.reverse()
            print("["+",".join(dq)+"]")
