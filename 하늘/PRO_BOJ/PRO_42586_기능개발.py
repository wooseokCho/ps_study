def solution(progresses, speeds):
    
    answer = [] 
     
    lst =[]
    for p,s in zip(progresses, speeds): 
        lst.append(round((100-p) / s))
    
    stack=[]
    cnt = 1
    for day in lst: 
        
        if stack and stack[-1] >= day:
            cnt+=1
            stack.pop() 
            answer.append(cnt) 
        else:
            cnt =0
            stack.append(day) 

            
    return answer
