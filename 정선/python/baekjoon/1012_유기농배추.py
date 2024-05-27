# 입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다. 
# 그 다음 줄부터 각각의 테스트 케이스에 대해 첫째 줄에는 배추를 심은 배추밭의 가로길이 M(1 ≤ M ≤ 50)과 세로길이 N(1 ≤ N ≤ 50), 
# 그리고 배추가 심어져 있는 위치의 개수 K(1 ≤ K ≤ 2500)이 주어진다. 그 다음 K줄에는 배추의 위치 X(0 ≤ X ≤ M-1), Y(0 ≤ Y ≤ N-1)가 주어진다. 
# 두 배추의 위치가 같은 경우는 없다.


# 배추의 위치 정렬
# 좌표 저장 list를 도는 방법이 있고
# 표에 표시해서 탐색하는 방법이 있고 -> 이게 더 날듯, 근데 이거로 하면 맵을 싹 돌아야되는데, visited => 없어도 될듯?

import sys
sys.setrecursionlimit(10**6)
def check_inside_map(y, x) :
    if 0 <= y < N and 0 <= x < M :
        return True
    else :
        return False

def find_region(y, x) :
    status_map[y][x] = 0
    directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
    for dy, dx in directions :
        ny, nx = y+dy, x+dx
        if check_inside_map(y+dy, x+dx) :
            if status_map[ny][nx] == 1:
                find_region(ny, nx)

# def print_status_map() :
#     for y in range(N) :
#         tmp_str = ''
#         for x in range(M) :
#             if status_map[y][x] == 1 :
#                 tmp_str += "\033[43m"
#             tmp_str += f"{status_map[y][x]}\033[0m "
#         print(tmp_str)

T = int(input())

for _ in range(T) :
    cnt = 0
    M, N, K = map(int, input().split())
    status_map = [[0 for _ in range(M)] for _ in range(N)]

    for _ in range(K) :
        x, y = map(int, input().split())
        status_map[y][x] = 1
    
    for y in range(N) :
        for x in range(M) :
            if status_map[y][x] == 0 :
                continue
            else :
                # print(f"FIND START {y}, {x}")
                # print_status_map()
                find_region(y, x)
                # print(f"FIND END   {y}, {x}")
                # print_status_map()
                cnt += 1
                
    print(cnt)                

