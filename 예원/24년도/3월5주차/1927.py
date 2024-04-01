import heapq
import sys
input = sys.stdin.readline
min_heap = []
n = int(input())
for i in range(n):
    a = int(input().rstrip())
    
    if a == 0:
        if len(min_heap) == 0:
            print(0)
        else:
            min_val = heapq.heappop(min_heap)
            print(min_val)
    else:
        heapq.heappush(min_heap, a)


