# 마이너스 시 나눗셈 되면 마이너스 나오는 것 주의하기
import math

N = input()
A = list(map(int, input().split()))
B, C  = map(int, input().split())

result = 0

for a in A :
    # print(math.ceil((a - B) / C) + 1)
    if (a - B) >= 0 :
        result += math.ceil((a - B) / C) + 1
    else :
        result += 1

print(result)