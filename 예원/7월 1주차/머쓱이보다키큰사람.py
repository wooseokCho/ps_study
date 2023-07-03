def solution(array, height):
    array.append(height)
    array.sort(reverse=True)       
    return array.index(height)