zero = [1,0,1]
one = [0,1,1]
def fibo(n):
    if n>=len(zero):
        for i in range(n):
            zero.append(zero[i-1]+zero[i-2])
            one.append(one[i-1]+one[i-2])
    print("{} {}".format(zero[n], one[n]))
T=int(input())
for _ in range(T):
    fibo(int(input()))


