def solution(array, n):
    array.sort(key=lambda x: (abs(x-n), n))
    return array[0]