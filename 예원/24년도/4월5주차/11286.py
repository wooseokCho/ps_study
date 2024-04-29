import heapq, sys
input = sys.stdin.readline
min_heap = []
n=int(input())
for i in range(n):
    num = int(input())
    if num == 0:
        if min_heap:
            _, min_value = heapq.heappop(min_heap)
            print(min_value)
        else:
            print(0)
    else:
        heapq.heappush(min_heap, (abs(num), num))
