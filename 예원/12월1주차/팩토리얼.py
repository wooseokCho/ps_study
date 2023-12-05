def solution(n):
    factorial = 1
    i=1
    while (factorial <= n):
        i= i+1
        factorial = factorial*i
    return i-1