def solution(n):
    return len([number for number in range(1,n+1) if n%number ==0])