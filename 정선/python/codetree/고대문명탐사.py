import sys
sys.stdin = open('/Users/imjungsun/Desktop/ps_study/정선/python/codetree/example.txt', 'r')
import copy

# 돌아가는건 맞았던거 같고.... 왼쪽이 비지 않고 ㄷ쏙 들어갈 때 예외처리 안해준게 문제
# 좀 침착하게 하지... 왜 ... 왜 몰랐을까...

DBG = False

R, C, K = map(int, input().split())
ufos = []
for _ in range(K) :
    ufos.append(map(int, input().split()))
tmp = []
for (c, d) in ufos :
    tmp.append([c-1, d])
ufos = tmp
margin = 3
Rm = R + margin
mmap = [[-1 for _ in range(C)] for _ in range(Rm)]
exs = []

directions = [[-1, 0], [0, 1], [1, 0], [0, -1]] # 상우하좌 -> 우하

def inside_map(r, c, R) :
    if 1<=r<R-1 and 1<=c<C-1:
        return True
    return False

def inside_map_alian(r, c, R) :
    if 1<=r<R and 1<=c<C:
        return True
    return False

def overlap(r, c) :
    for (dr, dc) in directions :
        tr, tc = r + dr, c + dc
        if inside_map(r, c, Rm) :
            if mmap[tr][tc] != -1 :
                return True
            
    return False

def move_ufo(r, c, ex, opt) :
    # 다른 ufo 존재하는지 알기 위해 status 저장, ufo 아이디 저장해서 출구 정보 있는 리스트에 바로 접근하게
    # 출구 정보 있는 리스트 저장
    if opt == 'ldown' and not overlap(r, c-1) :
        nr, nc = r + 1, c - 1
        ne = (ex + 3) % 4
    elif opt == 'rdown' and not overlap(r, c+1) :
        nr, nc = r + 1, c + 1
        ne = (ex + 1) % 4 # -1과 동일
    else :
        nr, nc = r + 1, c
        ne = ex
    if inside_map(nr, nc, Rm) :
        if not overlap(nr, nc) :
            return True, nr, nc, ne
    return False, r, c, ex

def save_mmap(r, c, id) :
    mmap[r][c] = id
    for (dr, dc) in directions :
        tr, tc = r + dr, c + dc
        mmap[tr][tc] = id

def cr() : return "\033[031m"        
def cg() : return "\033[032m"        
def cy() : return "\033[033m"        
def cb() : return "\033[034m" 
def c1() : return "\033[035m"   
def c2() : return "\033[036m"     
def br() : return "\033[041m"        
def bg() : return "\033[042m"        
def by() : return "\033[043m"        
def bb() : return "\033[044m"   
def b1() : return "\033[045m"   
def b2() : return "\033[046m" 
def b3() : return "\033[047m" 
def b4() : return "\033[048m" 
def bgray() : return "\033[100m"  
bgs = [bg, by, bb, b1, b2, b3, b4]
cgs = [cg, cy, cb, c1, c2]

def print_mmap() :
    for i, m in enumerate(mmap) :
        tmp = ""
        for j, v in enumerate(m) :
            if [i,j] in exs :
                tmp += br()
                # tmp += cgs[v%len(cgs)]()
            elif v != -1 :
                tmp += bgs[v%len(bgs)]()
            elif 0 <= i < 3 :
                tmp += bgray()
            tmp += f"{v+1}\033[0m "
        print(tmp)

def print_mmap_with_alian(r, c) :
    for i, m in enumerate(mmap) :
        tmp = ""
        for j, v in enumerate(m) :
            if [i,j] == [r,c] :
                tmp += bgray()
            elif [i,j] in exs :
                tmp += br()
                # tmp += cgs[v%len(cgs)]()
            elif v != -1 :
                tmp += bgs[v%len(bgs)]()
            elif 0 <= i < 3 :
                tmp += bgray()
            tmp += f"{v+1}\033[0m "
        print(tmp)

def print_tmp_mmap(r, c, e, id) :
    tmp_mmap = copy.deepcopy(mmap)
    tmp_mmap[r][c] = id
    for (dr, dc) in directions :
        tr, tc = r + dr, c + dc
        tmp_mmap[tr][tc] = id
    dr, dc = directions[e]

    for i, m in enumerate(tmp_mmap) :
        tmp = ""
        for j, v in enumerate(m) :
            if [i,j] == [r+dr, c+dc] :
                tmp += br()
                tmp += cgs[v%len(cgs)]()
            elif v != -1 :
                tmp += bgs[v%len(bgs)]()
            tmp += f"{v+1}\033[0m "
        print(tmp)

def print_init_ufo(r, c, e, id) :
    tmp_mmap = [[-1 for _ in range(C)] for _ in range(3)]
    tmp_mmap[r][c] = id
    for (dr, dc) in directions :
        tr, tc = r + dr, c + dc
        tmp_mmap[tr][tc] = id
    dr, dc = directions[e]

    for i, m in enumerate(tmp_mmap) :
        tmp = ""
        for j, v in enumerate(m) :
            if v != -1 :
                tmp += bgs[v%5]()
            if [i,j] == [r+dr, c+dc] :
                tmp += br()
            tmp += f"{v+1}\033[0m "
        print(tmp)

def convert_exit(r, c, ex) :
    dr, dc = directions[ex]
    return [r+dr, c+dc]

def move_alian(r, c) :
    global lowest, lowest_r, lowest_c
    nid = mmap[r][c]
    for (dr, dc) in directions :
        nr, nc = r + dr, c + dc 
        if inside_map_alian(nr, nc, Rm) and not visited[nr][nc] :
            if nid == mmap[nr][nc] :
                visited[nr][nc] = True
                move_alian(nr, nc)
                if lowest < nr :
                    lowest = nr
                    lowest_r = nr
                    lowest_c = nc
            elif mmap[nr][nc] != -1 and [r, c] in exs:
                visited[nr][nc] = True
                move_alian(nr, nc)
                if lowest < nr :
                    lowest = nr
                    lowest_r = nr
                    lowest_c = nc

if DBG : print_mmap()

result = 0

for id, (c, ex) in enumerate(ufos) :
    r = 1
    if DBG :
        print(f"\n\n{id}")
        print_init_ufo(r, c, ex, id)
    
    # 우주석 이동
    w_idx = 0
    while True :
        # print(f"{id} GOGO {w_idx}th")
        # print_tmp_mmap(r, c, ex, id)
        w_idx += 1
        flag, nr, nc, ne = move_ufo(r, c, ex, 'down')
        if not flag : # 이동 못하면
            flag, nr, nc, ne = move_ufo(r, c, ex, 'ldown')
            if not flag : # 이동 못하면
                flag, nr, nc, ne = move_ufo(r, c, ex, 'rdown')
        if not flag :
            break
        r, c, ex = nr, nc, ne
    
    if r >= 4 :
        exs.append(convert_exit(r, c, ex))
        save_mmap(r, c, id)
        # 우주인 이동
        visited = [[False for _ in range(C)] for _ in range(Rm)]
        lowest = 0
        lowest_r, lowest_c = 0, 0
        move_alian(r, c)
        if DBG :
            print_mmap_with_alian(lowest_r, lowest_c)
            print(f"score : {lowest - 2}")
        result += lowest - 2
    else :
        mmap = [[-1 for _ in range(C)] for _ in range(Rm)]
        exs = []

    # if DBG :
    #     print(r, c, id)
    #     print(exs)
    #     print_mmap()

print(result)
    
# R행 C열
# 위를 1행, 아래를 R열

# 출구 존재
# 쭉 내려오는거 안되면
# 좌측 회전
# 우측 회전
# 넘으면, 맵이 초기화 됨

# 출구 있음
# 이동 후 정령이 갈 수 있는 맨 마지막 최종 위치가 점수가 됨
# 첫 번째 줄에는 숲의 크기를 의미하는 R, C, 정령의 수 K가 공백을 사이에 두고 주어집니다.
# 그다음 줄부터 K개의 줄에 거쳐 각 골렘이 출발하는 열 c 
# i
#  , 골렘의 출구 방향 정보 d 
# i
#  가 공백을 사이에 두고 주어집니다.
# 골렘의 출구 방향 정보 d 
# i
#  는 0과 3 사이의 수로 주어지며 각각의 숫자 0,1,2,3은 북, 동, 남, 서쪽을 의미합니다. (상우하좌)

# 출력 형식
# 첫번째 줄에 각 정령들이 최종적으로 위치한 행의 총합을 출력하세요.