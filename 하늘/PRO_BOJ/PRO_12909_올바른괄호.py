def solution(s): 
    
    stack = []
    if s[0]==")":
        return False 
      
    for elem in s:
        if elem == "(":
            stack.append(elem)
        else:
            if not stack:  
                return False

            elif stack: 
                out = stack.pop()  
                if out == ")":
                    return False
    if stack:  
        return False
    else :
        return True
