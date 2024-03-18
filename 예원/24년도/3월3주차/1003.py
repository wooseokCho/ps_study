def count(n):
    if (n == 0):
        zeros = 1
        ones = 0
        
    elif (n == 1):
        zeros = 0
        ones = 1
    else:
        zeros = 1
        ones = 0
        for _ in range(n):
            zeros, ones = ones, zeros+ones
    return zeros, ones    
T=int(input())    
for _ in range(T):
    N = int(input())
    zeros, ones = count(N)
    print(zeros, ones)