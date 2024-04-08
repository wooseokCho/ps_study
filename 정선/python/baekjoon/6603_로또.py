def dfs(depth, idx) :
    global n
    if depth == 6 :
        for i in range(n) :
            if visited[i] :
                print(nums[i], end=" ")
        print()
    else :
        for i in range(idx, n) :  
            visited[i] = True
            dfs(depth+1, i+1)
            visited[i] = False

# DGB
# nums = [1, 2, 3, 4, 5, 6, 7]
# nums.sort()
# n = len(nums)
# visited = [False for _ in range(n)]
# dfs(0, 0)
            
n = 1
while n != 0 :
    nums = list(map(int, input().split(" ")))
    n, nums = nums[0], nums[1:]
    visited = [False for _ in range(n)]
    dfs(0, 0)
    print()