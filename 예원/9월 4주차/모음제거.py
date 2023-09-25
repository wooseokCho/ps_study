def solution(my_string):
    return "".join([i for i in my_string if not(i in "aeiou")])