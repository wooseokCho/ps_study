def solution(num,k):
    return -1 if str(k) not in str(num) else str(num).find(str(k))+1