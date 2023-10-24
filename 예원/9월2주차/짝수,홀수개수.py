def solution(num_list):
    answer = [0,0]
    for n in num_list:
        answer[n%2]+=1
    return answer