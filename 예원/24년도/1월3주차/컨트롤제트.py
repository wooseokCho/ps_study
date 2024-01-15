def solution(s):
    s=s.split()
    stack=[]
    for i in s:
        if i == "Z":
            if stack:
                stack.pop()
        else:
            stack.append(int(i))
    return sum(stack)