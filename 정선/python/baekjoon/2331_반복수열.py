import math

def multiply_digits(A, P) :
    result = 0
    while A > 0 :
        result += math.pow(A % 10, P)
        A //= 10
    return int(result)
    
A, P = map(int, input().split())

sequence = []
loop_flag = True

while loop_flag :
    sequence.append(A)
    A = multiply_digits(A, P)
    for idx, num in enumerate(sequence) :
        if num == A :
            print(idx)
            loop_flag = False
            break

