from collections import deque
n,m = map(int, input().split())
graph = [0]*101
ladder, snake = {}, {}
for _ in range(n):
    a,b = map(int, input().split())
    ladder[a] = b
for _ in range(m):
    a,b = map(int, input().split())
    snake[a] = b
def bfs():
    visited = [False]*101
    queue = deque([(1, 0)]) #초기화 시 리스트 안에 튜플
    while queue:
        pos, count = queue.popleft()
        if pos == 100:
            return count
        for i in range(1,7):
            next_pos = pos +i
            if next_pos > 100:
                continue
            if next_pos in ladder:
                    next_pos = ladder[next_pos]
            elif next_pos in snake:
                next_pos = snake[next_pos]
            if not visited[next_pos]:
                visited[next_pos] = True
                queue.append((next_pos, count+1))    
    return -1    
print(bfs())

