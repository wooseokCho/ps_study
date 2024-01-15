def solution(array):
    count = 0
    for num in array:
        count+=str(num).count("7")
    return count