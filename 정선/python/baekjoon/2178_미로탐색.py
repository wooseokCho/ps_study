from collections import deque

n, m = input().rstrip().split(" ")
n = int(n)
m = int(m)
maze = []
for _ in range(n) :
    maze.append(list(map(int, list(input().rstrip()))))

# test input
# n = 4
# m = 6
# maze = []
# maze_tmp = ['101111', '101010', '101011', '111011']
# for mt in maze_tmp :
#     maze.append(list(map(int, list(mt))))

search = [[-1, 0], [0, -1], [1, 0], [0, 1]]

import sys
input=sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
# dfs로 풀이시 시간초과 - 최단거리 탐색이 아니라서?
# https://www.acmicpc.net/problem/24444 풀어보기
def find_maze_dfs(x, y) :
    state = maze[y][x]

    for s in search :
        sx, sy = s
        nx = x+sx
        ny = y+sy
        if 0 <= nx < m and 0 <= ny < n : 
            if maze[ny][nx] != 0 :
                if maze[ny][nx] == 1 or maze[ny][nx] > state + 1 :
                    maze[ny][nx] = state + 1
                    find_maze_dfs(nx, ny)

def find_maze_bfs() :
    q = deque([(0,0)])
    
    while q :
        x, y =  q.popleft()
        state = maze[y][x]
        for s in search :
            sx, sy = s
            nx = x+sx
            ny = y+sy
            if 0 <= nx < m and 0 <= ny < n : 
                if maze[ny][nx] != 0 :
                    if maze[ny][nx] == 1 :
                        maze[ny][nx] = state + 1
                        q.append((nx, ny))

# find_maze_dfs(0, 0)
find_maze_bfs()
print(maze[n-1][m-1])