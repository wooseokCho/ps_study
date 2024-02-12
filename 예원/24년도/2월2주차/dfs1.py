def solution(numbers, target):
    def dfs(index, value):
        nonlocal answer
        if index == len(numbers):
            if value == target:
                answer +=1
            return
        dfs(index+1, value + numbers[index])
        dfs(index+1, value-numbers[index])
    answer = 0
    dfs(0,0)
    return answer