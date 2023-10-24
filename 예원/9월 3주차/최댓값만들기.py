def solution(numbers):
    numbers.sort()
    return numbers[-2]*numbers[-1]