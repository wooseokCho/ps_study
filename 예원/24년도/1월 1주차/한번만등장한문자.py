from collections import Counter
def solution(s):
    counter = Counter(s)
    unique_chars = [char for char, count in counter.items() if count ==1]
    sorted_chars = sorted(unique_chars)
    return "".join(sorted_chars)