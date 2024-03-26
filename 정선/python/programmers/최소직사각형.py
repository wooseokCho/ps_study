# 완전탐색 lv1
# https://school.programmers.co.kr/learn/courses/30/lessons/86491?language=python3
def solution(sizes):
    long_max = 0 # 긴것중에 가장 긴거
    long_min = 0 # 짧은거중에 가장 긴거, 이름을..
    
    for s in sizes :
        if s[0] > s[1] :
            tmp_long, tmp_shrt = s[0], s[1]

        else :
            tmp_long, tmp_shrt = s[1], s[0]
            
        if tmp_long > long_max :
            long_max = tmp_long
        if tmp_shrt > long_min :
            long_min = tmp_shrt
    
    return long_min * long_max