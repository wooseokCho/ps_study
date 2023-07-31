
def solution(s):
    stack = []   
    
    for char in s:
        print(stack)
        if stack and stack[-1] == char: 
            stack.pop()   
        else:
            stack.append(char)   
    
    output = ''.join(stack) 
    
    if output =='' :
        return 1
    else:
        return 0 
