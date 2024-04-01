#만일 합계의 절반보다 큰 수가 있다면, -1을 return
#만일 절반보다 작으면 작은 곳에 넣어줌
#만일 절반보다 크다면 원래 컸던 곳에 넣어줌
from collections import deque
def solution(queue1, queue2):
    half = sum(queue1+queue2) / 2
    count = 0
    while sum(queue1) !=  half and sum(queue2) != half:
        if sum(queue1) < half: #queue1의 합이 작을때
            a = queue2.pop(0)
            if a > half:
                count = -1
                print(count)
                break
            queue1.append(a)
            count+=1
            print("1:", count)
            
            continue
        elif sum(queue2) < half: #queue2의 합이 작을때
            b= queue1.pop(0)
            if b > half:
                count = -1
                print(count)
                break
            queue2.append(b)
            count+=1
            print("2:", count)
            continue
        
    print(count)
    return count

queue1 = [1, 2, 1, 2]
queue2 = [1, 10, 1, 2]
solution(queue1, queue2)