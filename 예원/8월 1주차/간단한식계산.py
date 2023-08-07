def solution(binomial):
    a, op, b = binomial.split()
    a=int(a)
    b=int(b)
    if op =="+":
        result=a+b
    elif op =="-":
        result=a-b
    elif op=="*":
        result=a*b
    return result