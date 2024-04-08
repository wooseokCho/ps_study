# 다시 풀어보기
def dfs(depth, index) :
    global min_diff
    if depth == N//2 :
        power1, power2 = 0, 0
        for i in range(N) :
            for j in range(N) :
                if visited[i] and visited[j] :
                    power1 += power_map[i][j]
                elif not visited[i] and not visited[j] :
                    power2 += power_map[i][j] 
        diff_power = abs(power1 - power2)
        if min_diff > diff_power :
            min_diff = diff_power
    else :
        for i in range(index, N) :
            if not visited[i] :
                visited[i] = True
                dfs(depth+1, i+1)
                visited[i] = False

N = int(input())
power_map = []
for _ in range(N) :
    power_map.append(list(map(int, input().split(" "))))

min_diff = 1e9
persons = [x for x in range(N)]
visited = [False for _ in range(N)]

dfs(0, 0)
print(min_diff)