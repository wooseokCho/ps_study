# 지도
# 동쪽 남쪽
# 주사위 위치
# 명령개수
# 동 1 서 2 남 3 북 4

# 0인 경우 주사위 숫자가 복사되고,
# 0이 아닌경우 바닥 숫자가 주사위에 복사
# 맨 윗면에 써져있는 수를 출력

# 주사위를 어떻게 나타내지?
# 리스트랑 인덱스로 나타내야겠다

# call by ref, by value 때문인가? 값이 이상한게?
# 추가로 찾아보고,
# 아래 코드도 깔끔하게 정리하기
def copy_dice_n_map() :
    # 주사위 카피
    if map_info[y][x] == 0 :
        map_info[y][x] = h[up_to_down(h_idx)]
    else :
        h[up_to_down(h_idx)] = map_info[y][x]
        map_info[y][x] = 0

def up_to_down(idx) :
    return (idx + 2) % 4

h_idx, w_idx = 0, 0

h = [0, 0, 0, 0]
w = [0, 0, 0, 0]

mw, mh, x, y, _ = map(int, input().split())
map_info = []

for _ in range(mw) :
    map_info.append(list(map(int, input().split(" "))))

k_list = list(map(int, input().split()))


for k in k_list :
    copy_dice_n_map()
    print(f"\n\n명령 {k}")
    # 1234
    # 동서남북
    # 우좌하상
    # 위치마다 변경하도록
    if k == 3 : # 위
        if y <= 0 :
            continue
        y -= 1
        h_idx = (h_idx + 1) % 4
        w[w_idx] = h[h_idx]
        w[(w_idx+2)%2] = h[(h_idx+2)%2]

    elif k == 4 : # 하
        if y >= mh :
            continue
        y += 1
        h_idx = (h_idx - 1) % 4
        w[w_idx] = h[h_idx]
        w[(w_idx+2)%2] = h[(h_idx+2)%2]
    
    elif k == 1 : # 오
        if x >= mw :
            continue
        x += 1
        w_idx = (w_idx - 1) % 4
        h[h_idx] = w[w_idx]
        h[(h_idx+2)%2] = w[(w_idx+2)%2]

    elif k == 2 : # 왼
        if x <= 0 :
            continue
        x -= 1
        w_idx = (w_idx + 1) % 4
        h[h_idx] = w[w_idx]
        h[(h_idx+2)%2] = w[(w_idx+2)%2]
    
    for i, mi in enumerate(map_info) :
        if i == y :
            print("!", end="")
        else :
            print(" ", end="")
        print(" ".join(map(str, mi)))
    
    print(f"x, y : {x}, {y}")
    print(h, h_idx)
    print(w, w_idx)


        
