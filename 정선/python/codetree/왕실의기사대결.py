# 입력
# L N Q # L : 체스판 크기, N : 기사 수, Q : 명령
# L개 줄에 겹쳐 LxL 체스판 정보, 0 : 빈칸, 1 : 함정, 2: 벽
# N명 기사 정보(순서대로) : r, c, h, w, k - 위치 (r, c), 방패 (h, w) 체력 k
# Q개 명령 : i, d i번째 기사 d로 한칸 이동(사라진 기사 번호가 주어질 수 있음)
# d (0, 1, 2, 3) : 상 우 하 좌
# 처음에는 기사들끼리 겹쳐지지 않고, 기사와 벽은 겹쳐서 주어지지 않음

# 출력
# Q 명령 후 생존 기사들의 받은 총 데미지 합

DBG = False
class Knight :
    def __init__(self, r, c, h, w, k):
        self.r = r
        self.c = c
        self.h = h # 방패 바로 더해주려고 -1 해줌, 인덱싱할 땐 그냥 써야되네;...
        self.w = w
        self.k = k
        self.d = 0
        self.status = True
    def get_infos(self):
        return [self.r, self.c, self.h, self.w]

# 입력 ################################################
L, N, Q = map(int, input().split(" "))
mmap = []
knights = []
orders = []
total_damage = [0] * N
for _ in range(L) :
    mmap.append(list(map(int, input().split(" "))))
for _ in range(N) :
    r, c, h, w, k = map(int, input().split(" "))
    knights.append(Knight(r, c, h, w, k))
for _ in range(Q) :
    orders.append(map(int, input().split(" ")))
######################################################

def check_mapout(r, c, h, w) :
    if 1 <= r <= L and 1 <= c <= L and 1 <= r+h-1 <= L and 1 <= c+w-1 <= L :
        return True
    return False
def check_overlap(tr, tc, h, w, other_knight) :
    ot_r, ot_c, ot_h, ot_w = other_knight.get_infos()
    # 잘못!! 어떤게 더 클지 모르니까 둘다 해줘야되네...
    if (tr <= ot_r <= tr+h-1) or (tr <= ot_r+ot_h-1 <= tr+h-1) : # 세로 방향 겹치는지
        if (tc <= ot_c <= tc+w-1) or (tc <= ot_c+ot_w-1 <= tc+w-1): # 가로 방향 겹치는지
            return True
    if (ot_r <= tr <= ot_r+ot_h-1) or (ot_r <= tr+h-1 <= ot_r+ot_h-1):  # 세로 방향 겹치는지
        if (ot_c <= tc <= ot_c+ot_w-1) or (ot_c <= tc+w-1 <= ot_c+ot_w-1):  # 가로 방향 겹치는지
            return True

    return False

def get_max_value(tr, tc, h, w) :
    max_value = 0
    for m in mmap[tr - 1:tr + h - 1] : # tr이 1부터 시작하니까
        tmp = max(m[tc - 1:tc + w - 1])
        if max_value < tmp :
            max_value = tmp
    return max_value

def get_damage(r, c, h, w) :
    damage = 0
    for m in mmap[r - 1:r + h - 1] :
        for v in m[c - 1:c + w - 1] :
            if v == 1 : damage+=1
    return damage

# 뭐가 하나라도 안되면 False로 return해서 돌지 않도록
# 최종으로 된다고 하면 True랑 history return해서 위치 바꿔주면서 패널티 세기
def push_knights(knight, kidx, move, history):
    # 이동 시 밀 수 있는지 검사
    mr, mc = move
    tr, tc = knight.r+mr, knight.c+mc
    h, w = knight.h, knight.w
    if not check_mapout(tr, tc, h, w) : # 맵 범위 밖이거나
        if DBG :print(f"NO! knight {kidx+1} - map out")
        return False, history # 이동 불가
    elif get_max_value(tr, tc, h, w) == 2 : # 벽이 있으면
        if DBG : print(f"NO! knight {kidx+1} - wall")
        return False, history
        # 이동 불가
    else : # 벽이 없다면 이동 가능
        if DBG :print(f"GO! knight {kidx+1}")
        history[kidx] = [tr, tc] # new tr, tc
        for idx, other_knight in enumerate(knights): # 기사가 있는지 검사
            if other_knight.status : # 기사가 살아있을 때
                if idx != kidx and idx not in history.keys(): # 자기 자신이 아니고 다른 기사랑 만났을 때, 본 것들이 아닐 때
                    if DBG : print(f"-> check knight {idx+1}")
                    if check_overlap(tr, tc, h, w, other_knight) : # 겹치는 영역이 있으면
                        if DBG: print(f"overlap knight {idx + 1} info {other_knight.r, other_knight.c, other_knight.h, other_knight.w}")
                        flag, history = push_knights(other_knight, idx, [mr, mc], history) # 다시 밀어내기
                        if not flag :
                            return False, None
    return True, history

direct = ['상', '우', '하', '좌']
directions = [[-1, 0], [0, 1], [1, 0], [0, -1]] # 상우하좌
for (kidx, d) in orders :
    kidx -= 1
    if DBG : print(f"!!! Order Knight : {kidx+1}, {direct[d]}")
    if knights[kidx].status : # 기사가 살아있으면
        flag, history = push_knights(knights[kidx], kidx, directions[d], {})
        if DBG : print(flag, history)
        if flag :
            for hkidx, (nr, nc) in history.items() : # 좌표 업데이트, 업데이트 하면서 패널티도 받게 하기
                knights[hkidx].r, knights[hkidx].c = nr, nc # 좌표값 업데이트
                if hkidx != kidx:  # 명령 아닌거만 패널티
                    h, w = knights[hkidx].h, knights[hkidx].w   # 쉽게 쓸라고, 노의미
                    knights[hkidx].d += get_damage(nr, nc, h, w)
                    if knights[hkidx].k <= knights[hkidx].d :
                        knights[hkidx].status = False

result = 0
for kidx, knight in enumerate(knights) :
    if knight.status :
        if DBG : print(f"{kidx+1}D : {knight.d}")
        result += knight.d

print(result)
