def solution(s):
    answer = "".join(sorted([ch for ch in s if s.count(ch) == 1]))
    return answer