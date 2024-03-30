import copy
from itertools import combinations

DBG = False
 
# 굳이 필요 없는 코드 -> 벽 주변이 아닌 경우에도 확인이 필요
# def find_wall_candidate(mmap) :
#     mmap = copy.deepcopy(mmap)
#     directions = [[-1, 0], [1, 0], [0, -1], [0, 1], [-1, -1], [1, -1], [-1, 1], [1, 1]]  # 상하좌우 대각선

#     wall_loc_candidates = []

#     for wall in wall_loc :
#         for direction in directions :
#             wc_y = wall[0] + direction[0]
#             wc_x = wall[1] + direction[1]

#             if 0 <= wc_y < N and 0 <= wc_x < M and mmap[wc_y][wc_x] == 0 :
#                 wall_loc_candidates.append([wc_y, wc_x])
#                 mmap[wc_y][wc_x] = 1

#     # 벽에 붙어서 제외할 수 있는 케이스 추가
#     for wc_y in [0, 1, -1, -2] :
#         for wc_x in range(M) :
#             if mmap[wc_y][wc_x] == 0 :
#                 wall_loc_candidates.append([wc_y, wc_x])
#                 mmap[wc_y][wc_x] = 1

#     for wc_y in range(N) :
#         for wc_x in [0, 1, -1, -2] :
#             if mmap[wc_y][wc_x] == 0 :
#                 wall_loc_candidates.append([wc_y, wc_x])
#                 mmap[wc_y][wc_x] = 1

#     return wall_loc_candidates

def print_mmap(mmap) :
    for line in mmap :
        print(" ".join(map(str, line)))

def find_save_space(mmap, wall_candidate, virus_loc) :
    mmap = copy.deepcopy(mmap)
    virus_loc = copy.deepcopy(virus_loc)

    for wy, wx in wall_candidate :
        mmap[wy][wx] = 3

    save_space_size = 0

    while len(virus_loc) > 0 :
        vy, vx = virus_loc.pop(0)
        for dy, dx in [[-1, 0], [1, 0], [0, -1], [0, 1]] :
            ny, nx = vy+dy, vx+dx
            if 0 <= ny < N and 0 <= nx < M and mmap[ny][nx] == 0 :
                mmap[ny][nx] = 2
                virus_loc.append([ny, nx])

    for line in mmap :
        save_space_size += line.count(0)
    
    if DBG :
        print("##################")
        print(wall_candidate)
        print_mmap(mmap)

    return save_space_size

N, M = map(int, input().split()) # 세로, 가로

mmap = []
wall_loc = [] # location of wall
virus_loc = []
empty_loc = []

for y in range(N) :
    line = list(map(int, input().split()))

    for x, v in enumerate(line) :
        if v == 0 :
            empty_loc.append([y, x])
        if v == 1 :
            wall_loc.append([y, x])
        if v == 2 :
            virus_loc.append([y, x])

    mmap.append(line)

# wall_loc_candidates = find_wall_candidate(mmap)
# wall_candidates = combinations(wall_loc_candidates, 3)

wall_candidates = combinations(empty_loc, 3)

max_save_space_size = 0
for wall_candidate in wall_candidates :
    save_space_size = find_save_space(mmap, wall_candidate, virus_loc)

    if max_save_space_size < save_space_size :
        max_save_space_size = save_space_size

    if DBG :
        print(save_space_size)
        input()

print(max_save_space_size)