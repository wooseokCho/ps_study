def solution(phone_number):
    answer = ''
    back = phone_number[-4:]
    for i in range(len(phone_number[:-4])):
        answer += '*'
    answer +=back
    
    return answer
