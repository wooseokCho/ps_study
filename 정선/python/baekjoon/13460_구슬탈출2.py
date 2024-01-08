# https://www.acmicpc.net/problem/13460
# 5 5
# #####
# #..B#
# #.#.#
# #RO.#
# #####

N, M = map(int, input().split(" "))
map = []
r_loc = []
b_loc = []
h_loc = []

for w in range(N) :
    line = input().split("")
    if len(r_loc) == 0 and line.index('R')  :
        r_loc = [w, line.index('R')]
    if len(b_loc) == 0 and line.index('B')  :
        b_loc = [w, line.index('B')]
    if len(b_loc) == 0 and line.index('B')  :
        b_loc = [w, line.index('B')]
    
    map.append(line)

# BFS
# 상하좌우 순서대로 모두 수행하며 결과 저장하면서 돌기
# 그럼 구슬 위치도 따로 저장해야 되는가?
# 상일 경우 [-1, 0], 하 [1, 0], 좌  [0, -1], 우 [0, +1]
# R,B 중 앞에 index 확인해서 가까운 것부터 벽에 부딪히기 전까지 이동하기
while True :
    ry, rx = r_loc
    if map[ry-1, rx] == '#' :
        break
    if map[ry-1, rx] == 'O' :
        break
    