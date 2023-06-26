def solution(n):
    answer = 1 
    for start in range(1, (n//2)+1): 
        sum=0
        for i in range(start,n):
            sum+=i
            if sum == n:
                answer +=1
                break
                
            if sum > n:  
                break

    return answer
 
