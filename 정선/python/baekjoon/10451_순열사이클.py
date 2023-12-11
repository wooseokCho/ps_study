cases = int(input())

for _ in range(cases) :
    num = int(input())
    graph = list(map(int, input().split(" ")))
                 
    cycle_num = 0
    visited = [False for _ in range(num)]

    for i, v in enumerate(visited) :
        if v == False :
            visited[i] = True
            idx = i
            while graph[idx] != i + 1 :
                idx = graph[idx] - 1
                visited[idx] = True
            cycle_num += 1

    print(cycle_num)