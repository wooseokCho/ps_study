import heapq, sys
input = sys.stdin.readline
max_heap = []
n=int(input())
for i in range(n):
    num = int(input())
    if num == 0:
        if max_heap:
            max_value = heapq.heappop(max_heap)
            print(-1*max_value)
        else:
            print(0)
    else:
        heapq.heappush(max_heap, -num)
