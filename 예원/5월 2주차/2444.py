N=int(input())
for i in range(N-1):
    print(" "*(N-1-i)+'*'*(2*(i+1)-1))
for i in range(N):
    print(" " * i + '*' * (2 * (N-i) - 1))