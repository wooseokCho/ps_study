def solution(my_string):
    num = ""
    total = 0
    for char in my_string:
        if char.isdigit():
            num+=char
        else:
            if num:
                total += int(num)
                num = ""
    if num:
        total += int(num)
    return total

