def solution(food):
    answer = ''
    for cal, num in enumerate(food) :
        answer += str(cal) * (num // 2)
    
    answer = f"{answer}0{answer[::-1]}"
    return answer