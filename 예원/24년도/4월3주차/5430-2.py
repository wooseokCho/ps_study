import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
for i in range(n):
    func = input().strip()
    m = int(input())
    flag = 1
    arr = input().strip()
    dq = deque(arr[1:-1].split(","))
    if m == 0:
        dq = deque()
    rev_count = 0 #true
    
    for i in range(len(func)):
        if func[i] == "R":
            rev_count +=1
        elif func[i] == "D":
            if len(dq) == 0:
                print("error")
                flag = 0
                break

            if rev_count%2 == 0:
                dq.popleft()
            else:
                dq.pop()
    if flag == 0:
        continue
    else:
        if rev_count%2 == 0:
            print("[" + ",".join(dq) + "]")
        else:
            dq.reverse()
            print("[" + ",".join(dq) + "]")

