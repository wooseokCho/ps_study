# 개인 풀이 과정 #########
# 지도
# 동쪽 남쪽
# 주사위 위치
# 명령개수
# 동 1 서 2 남 3 북 4

# 0인 경우 주사위 숫자가 복사되고,
# 0이 아닌경우 바닥 숫자가 주사위에 복사
# 맨 윗면에 써져있는 수를 출력

# 주사위 : 리스트랑 인덱스
# TODO : 다른 풀이 찾아보기

# 오답
# x, y가 바뀜 - 문제 잘 읽어보기
# 조건에 해당하지 않는 경우, 주사위에 복사 되면 안 됨
# 조건이 아닐 때 예외처리 잘 생각해주기
###########################


def up2down(idx) :
    return (idx + 2) % 4

# 아래 코드도 깔끔하게 정리하기
def copy_dice_n_map() :
    # 주사위 카피
    if map_info[y][x] == 0 :
        map_info[y][x] = h[up2down(h_idx)]
    else :
        h[up2down(h_idx)] = map_info[y][x]
        w[up2down(w_idx)] = map_info[y][x]
        map_info[y][x] = 0

# parameter init
map_info = []
h = [0, 0, 0, 0]
w = [0, 0, 0, 0]
h_idx, w_idx = 0, 0

# x가 세로, y가 가로
# get inputs
mh, mw, y, x, _ = map(int, input().split())
for _ in range(mh) :
    map_info.append(list(map(int, input().split(" "))))
k_list = list(map(int, input().split()))

# for dbg
direct=['우', '좌', '상', '하']

for k in k_list :
    # for dbg
    # print(f"\n\n({x}, {y})")

    # print(f"명령 {direct[k-1]} {k}")
    # tmp_str = " "+"  "*x+"!"
    # print(tmp_str)
    # for i, mi in enumerate(map_info) :
    #     if i == y :
    #         print("!", end="")
    #     else :
    #         print(" ", end="")
    #     print(" ".join(map(str, mi)))    
    # print(h, h_idx)
    # print(w, w_idx)


    if k == 3 or k == 4: # 상, 하
        if (k == 3 and y == 0) or (k == 4 and y == mh-1) :
            continue
        copy_dice_n_map()
        if k == 3 :
            tmp = -1
        else :
            tmp = 1
        y += tmp
        h_idx = (h_idx + tmp) % 4
        w[w_idx] = h[h_idx]
        w[(w_idx+2)%4] = h[(h_idx+2)%4]

    elif k == 1 or k == 2: # 우, 좌
        if (k == 1 and x == mw-1) or (k == 2 and x == 0) :
            continue
        copy_dice_n_map()
        if k == 1 :
            tmp = 1  # 우
        else :
            tmp = -1 # 좌
        x += tmp
        w_idx = (w_idx + tmp) % 4
        h[h_idx] = w[w_idx]
        h[(h_idx+2)%4] = w[(w_idx+2)%4]

    print(h[h_idx])

        

