def solution(s): 
    lst = s.split(' ')  
    lst = [i for i in lst if i !='']
    answer = ''
    
    if len(lst) == 0:
        answer = ''
        return answer

    else:
        for i in range(len(lst)): 
            answer += lst[i][0].upper() + lst[i][1:].lower()+ ' '
        answer = answer[:-1]
        
        return answer

   
