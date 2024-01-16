# https://www.acmicpc.net/problem/13460
# 5 5
# #####
# #..B#
# #.#.#
# #RO.#
# #####
import copy
    
def print_mmap(mmap) :
    for m in mmap :
        print(m)

def dbg_mmap(rx, ry, bx, by, visited) :
    visited = copy.deepcopy(visited)
    visited[ry][rx] = 'R'
    visited[by][bx] = 'B'
    print_mmap(visited)



N, M = map(int, input().split(" "))
mmap = []
visited = []
r_loc = []
b_loc = []
h_loc = []

for w in range(N) :
    line = input()
    if line.find('R') != -1 :
        r_loc = [w, line.find('R')]

    if line.find('B') != -1 :
        b_loc = [w, line.find('B')]

    mmap.append(list(line))
    visited.append(list(line.replace('R','.').replace('B','.')))

print(f"R {r_loc}")
print(f"B {b_loc}")

# BFS
# 상하좌우 순서대로 모두 수행하며 결과 저장하면서 돌기
# 결과들을 저장하는게 에반데... map도 저장해야되니까 굳이 해야되나? 구슬 위치만 저장하면 map은 바뀌지 않잖아
# 1번째 상하좌우 4개, 2번째 8, 3번째 16, .... 2^11 = 2048 경우의 수를 저장?하려면 하지...
# 위로 갔으면 위로 가는 조건은 담에 필요 없지, 가만히 있는 위치를 제외한다면 괜찮으려나?
# 상하좌우
# 상 : 하좌우
# 하 : 상좌우
# 이동 방향을 R, B이 이동할 수 있는 거리로 축소한다면?
# 시작할 때 아니면 3방향이 비어있는 경우는 있을 수 있지
# 왔던 방향을 되돌아가는 것 제외, 같은 방향 제외하면 2방향이지
# 그리고 이동할 수 있는 방향 추가하면 괜찮으려나?
# 최악의 수는 2048*2만큼 저장하는거임
# 그전에 끝나면 바로 gg
# 만약 성공하면 그냥 끝내면 되고 실패하면
# 그 횟수만큼은 다 돌아야지

# 상일 경우 [-1, 0], 하 [1, 0], 좌  [0, -1], 우 [0, +1]
# R,B 중 앞에 index 확인해서 가까운 것부터 벽에 부딪히기 전까지 이동하기
# 0 : 상, 1 : 하, 2 : 좌, 3 : 우
direct = [[-1, 0], [1, 0], [0, -1], [0, 1]]
dbg_direct = ['상', '하', '좌', '우']
# visited = [visited * 4] # visited X로 표시 아! R, B이 같이 있으니 애매하네...visited 뺴고 생각

tmp_queue = []
queue = [[-1, r_loc, b_loc]] # [direction, r_loc, b_loc]
cnt = 0

# dbg 필요
while True :
    for q in queue :
        before_direct, r_loc, b_loc = q
        for d_idx in range(4) :
            # 왔던 방향 되돌아가거나, 이전 방향과 같은 것 제외
            if before_direct == d_idx or (before_direct + 2) % 4 == d_idx:
                continue

            ry, rx = r_loc
            by, bx = b_loc

            print("\n>> BEFORE")
            dbg_mmap(rx, ry, bx, by, visited) 
            print(f"!! {dbg_direct[d_idx]}")

            my, mx = direct[d_idx]
            m_cnt = 1 

            rstop = False
            bstop = False
            false_flag = False
            success_flag = False

            # rstop, bstop 등 벽에 부딪혔을 때, 홀에 빠졌을 때 나눠서 해줘야되는뎀
            # n번째에서 모두 다 구멍에 빠지면 실패로 간주해야됨 => 구멍에 빠진거를 queue에 안 넣어주면 됨
            # 둘 다 구슬에 들어가는 경우는 false
            # 어렵구만 골드 1일만 해
            # 상하좌우 돌면서 벽, 구멍까리 순서대로 tmp_queue에 슉슈슉 넣어주기, queue처럼
            while not (rstop and bstop) :
                mcy = my * m_cnt
                mcx = mx * m_cnt
                print("R B")
                print(rstop, ry + mcy, rx + mcx)
                print(bstop, by + mcy, bx + mcx)

                # 순서 정해서, 상하좌우 중 더 위에 있는 것부터
                # direct 이거 곱해서, 더하고 더 큰 거부터 수행하기
                # 순서 정해줘야할텐데..

                ro = ry * my + rx * mx # r_order??
                bo = by * my + bx * mx 

                if ro > bo :
                    if not rstop :
                        if mmap[ry + mcy][rx + mcx] == "#" or "B":
                            rstop = True
                            ry, rx = ry + mcy - my, rx + mcx - mx
                        if mmap[ry + mcy][rx + mcx] == "O" :
                            success_flag = True
                    if not bstop :
                        if mmap[by + mcy][bx + mcx] == "#" or "R":
                            bstop = True
                            by, bx = by + mcy - my, bx + mcx - mx
                        if mmap[by + mcy][bx + mcx] == "O" :
                            false_flag = True
                else :
                    if not bstop :
                        if mmap[by + mcy][bx + mcx] == "#" or "R":
                            bstop = True
                            by, bx = by + mcy - my, bx + mcx - mx
                        if mmap[by + mcy][bx + mcx] == "O" :
                            false_flag = True
                    if not rstop :
                        if mmap[ry + mcy][rx + mcx] == "#" or "B":
                            rstop = True
                            ry, rx = ry + mcy - my, rx + mcx - mx
                        if mmap[ry + mcy][rx + mcx] == "O" :
                            success_flag = True
                    
                m_cnt += 1

            if success_flag and ~false_flag :
                print(cnt)
                break

            tmp_queue.append([d_idx, [ry, rx], [by, bx]])
            dbg_mmap(rx, ry, bx, by, visited) 
            input()

    queue = tmp_queue
    tmp_queue = []
    cnt += 1

    if success_flag and ~false_flag :
        print(cnt)
        break
