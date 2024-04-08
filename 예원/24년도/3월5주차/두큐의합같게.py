def solution(queue1, queue2):
    half = (sum(queue1)+sum(queue2)) / 2
    count = 0
    num=len(queue1)*2
    for i in range(num):
        q1 = sum(queue1)
        q2 = sum(queue2)
        if q1 ==  half and q2 == half:
            return count
        elif q1 < half: #queue1의 합이 작을때
            a = queue2.pop(0)
            if a > half:
                count = -1
                return count
            queue1.append(a)
            count+=1
            print("1:", count)
            continue
        elif q2 < half: #queue2의 합이 작을때
            b= queue1.pop(0)
            if b > half:
                count = -1
                return count
            queue2.append(b)
            count+=1
            print("2:", count)
            continue
        
    print(count)
    return count