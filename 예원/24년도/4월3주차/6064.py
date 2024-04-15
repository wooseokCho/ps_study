import sys
input = sys.stdin.readline
def gcd(a,b):
    while b!=0:
        a,b =b, a%b
    return a
def lcm(a,b):
    return a*b // gcd(a,b)
t= int(input())
for _ in range(t):
    m,n,x,y = map(int, input().split(' '))
    lcm_val = lcm(m,n)
    count = 0
    lcm_m = int(lcm_val/m)
    lcm_n = int(lcm_val/n) #5
    i,j = 0,0
    while (i < lcm_m and j < lcm_n):   
        val_a = m*i+x
        val_b = n*j+y
        if val_a > val_b:
            j+=1
        elif val_a < val_b:
            i+=1
        elif val_a == val_b:
            print(val_a)
            count+=1
            break
    if count == 0:
        print("-1")
