def real_round(num) :
    if num - int(num) >= 0.5 :
        result = int(num) + 1
    else :
        result = int(num)
    return result

N = int(input())
scores = []
for _ in range(N) :
    scores.append(int(input()))
scores.sort()
n = real_round(N / 100 * 15)
if n > 0 :
    scores = scores[n:-n]
if len(scores) > 0 :
    result = real_round(sum(scores) / len(scores))
else :
    result = 0
print(result)