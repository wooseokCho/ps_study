def solution(my_string):
    numbers=[int(s) for s in my_string if s.isdigit()]
    numbers.sort()
    return numbers