N, M, V = map(int, input().split(" "))

# graph 행렬 만들기
graph = [[0]*(N+1) for _ in range((N+1))]

for i in range(M) :
    a, b = map(int, input().split())
    graph[a][b] = graph[b][a] = 1

visited_dfs = [0]*(N+1)
visited_bfs = visited_dfs.copy()

def dfs(v) :
    # 방문 한 것  체크 -> 방문한 것은 stack에 넣지 않음
    visited_dfs[v] = 1
    print(v, end=' ')
    # Node에 연결된 번호들 체크해서 visited[] == 0면 stack에 넣어주기
    for i in range(1, N+1) :
        if graph[v][i] == 1 and visited_dfs[i] == 0 :
            dfs(i)

def bfs(v) :
    queue = [v]
    visited_bfs[v] = 1

    while queue :
        v = queue.pop(0)
        print(v, end=' ')
        for i in range(1, N+1) :
            if graph[v][i] == 1 and visited_bfs[i] == 0 :
                queue.append(i)
                visited_bfs[i] = 1

dfs(V)
print()
bfs(V)
