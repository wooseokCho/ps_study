N, r, c = map(int, input().split()) #N, r행 c열
power_two = 2**N
result = 0
def sol(N, r,c):
    global result
    if N == 1:  
        result += (r)*2+c
    else: #r행 c열
        half_size = 2 ** (N - 1)
        if (r+1) > half_size and (c+1) > half_size:
            result+=half_size*half_size*3
            sol(N-1, r-half_size,c-half_size)
        elif (r+1) <= half_size and (c+1) <= half_size:
            sol(N-1, r,c)
        elif (r+1) <= half_size and (c+1) > half_size:
            result+=half_size*half_size
            sol(N-1, r,c-half_size)
        elif (r+1) > half_size and (c+1) <= half_size:
            result+=half_size*half_size*2
            sol(N-1, r-half_size,c)
    return result
res = sol(N, r,c)
print(res)
#2 3 1 (4사분면)



