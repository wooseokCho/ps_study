def solution(brown, yellow): 
    answer = []
    num = brown + yellow
    
    for i in range(1, num//2) : 
        if num % i ==0:
            answer.append([i, num //i])
     
    lst = [sum(i) for i in answer]
 
    for i in answer:
        if sum(i)  == min(lst):
            answer = i
            
    answer = sorted(answer, reverse=True)

    return answer 
