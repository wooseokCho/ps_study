def solution(s):
    stack = []  # 스택을 활용하여 짝지어 있는 문자 추적 
    
    for char in s: 
        if stack and stack[-1] == char: 
            stack.pop()  # 짝이 맞는 문자이면 스택에서 제거
        else:
            stack.append(char)  # 짝이 맞지 않는 문자이면 스택에 추가
    
    output = ''.join(stack)   
    
    if output =='' :
        return 1
    else:
        return 0 
