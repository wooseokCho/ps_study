"""
4 2 10
7 4 5 6
"""

N, W, L = list(map(int, input().split(" ")))
trucks = list(map(int, input().split(" ")))

road = [0] * W

idx = 0
now_w = 0
time = 0

while idx < N :
    now_w -= road.pop(0)

    if now_w + trucks[idx] <= L :
        road.append(trucks[idx])
        now_w += trucks[idx]
        idx += 1
    else :
        road.append(0)

    time += 1

    # print(now_w)
    # print(" ".join(map(str, road)))
    # input()

print(time + W)