def solution(n):
    return sum(x**(2-x%2) for x in range(n+1) if n%2 == x%2)