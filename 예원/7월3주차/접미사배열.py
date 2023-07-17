def solution(my_string):
    str = [my_string[i:] for i in range(len(my_string))]
    sorted_str = sorted(str)
    return str