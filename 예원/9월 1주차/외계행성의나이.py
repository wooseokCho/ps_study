
def solution(age):
    str_age = str(age)
    age_programmers_962 = ''
    for digit in str_age:
        age_programmers_962 += chr(ord('a')+int(digit))
    return age_programmers_962
