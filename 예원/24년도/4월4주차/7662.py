import sys, heapq
input = sys.stdin.readline
t = int(input())

def isEmpty(nums):
    for item in nums:
        if item[1]>0:
            return False
        return True

for _ in range(t):
    k =int(input())
    min_heap, max_heap = [],[]
    nums = dict()
    for i in range(k):
        op, num = input().split()
        if op == "I":
            #중복 삽입일 때
            if num in nums:
                nums[num]+=1
            else:
                nums[num] = 1
                heapq.heappush(min_heap, num)
                heapq.heappush(max_heap, -num)

        elif op =="D":
            #큐가 비어있지 않을 때만
            if not isEmpty(nums.items()):   
                #최댓값을 제거
                if num ==1:
                    while -max_heap[0] not in nums or nums[-max_heap[0]]<1:
                        temp = -heapq.heappop(max_heap)
                        if temp in nums:
                            del(nums[temp])
                    nums[max_heap[0]]-=1    
                else:
                    while min_heap[0] not in nums or nums[min_heap[0]]<1:
                        temp = heapq.heappop(min_heap)
                        if temp in nums:
                            del(nums[temp])
                    nums[min_heap[0]]-=1      
            
#결과 출력
if isEmpty(nums.item()):
    print("EMPTY")
else:
    while min_heap[0] not in nums or nums[min_heap[0]]<1:
        heapq.heappop(min_heap)
    while -max_heap[0] not in nums or nums[max_heap[0]]<1:
        heapq.heappop(max_heap)
    print(-max_heap[0], min_heap[0])

