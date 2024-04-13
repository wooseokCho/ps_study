def get_distance_from_r() :
    d_list = [] # [d, r, c, idx] # d min으로 정렬, r max, c max로 정렬하기 위해서! d를 -해주면 정렬이 가능
    for idx, (sr, sc) in enumerate(santas) :
        if santa_status[idx] >= 0  :
            d = ((sr - rr) ** 2 + (sc - rc) ** 2)
            d_list.append([idx, d, sr, sc])
    d_list.sort(key=lambda x:(x[1], -x[2], -x[3])) # d, min으로 정렬 r max, c max 정렬
    return d_list[0]

def get_distance_from_s(sr, sc) : # td이 d보다 작아서 가까워질때만 d_list에 넣어줌, idx는 direction 우선순위
    direction = [[-1, 0], [0, 1], [1, 0], [0, -1]]  # 상우하좌
    d_list = []
    d = ((sr - rr) ** 2 + (sc - rc) ** 2) # 기존 거리보다 작아야됨
    for idx, (dr, dc) in enumerate(direction) :
        td = ((sr + dr - rr) ** 2 + (sc + dc - rc) ** 2)
        if d > td :
            d_list.append([idx, td, dr, dc])
    d_list.sort(key=lambda x:(x[1], x[0]))
    return d_list

def push_santa(tsr, tsc, mr, mc, sidx) : # 산타가 이동하는 좌표 tsr, tsc 받아서, push 해줌
    if 1 <= tsr <= N and 1 <= tsc <= N:  # 범위내 있으면 산타 index 변경, 기절 상태로 변경
        for siidx, santa in enumerate(santas): # 산타 위치 돌면서 자리에 산타 있는지 확인
            if [tsr, tsc] == santa and sidx != siidx: # 산타 겹치는 경우
                santas[sidx] = [tsr, tsc] # 기존 산타를 이동
                push_santa(tsr+mr, tsc+mc, mr, mc, siidx) # 이동할 산타 옮기기
                break
        santas[sidx] = [tsr, tsc]
    else : # 탈락 라운드 작성(나중에 점수에 +하면 됨), 근데 기절상태라면,,? <0일때만 +로 바꿔주는 함수 넣기
            santas[sidx] = [-N, -N] # 존재하지 않는 위치로 변경, distance 가장 높게 나오기 위해서 -N?
            santa_status[sidx] = -m
# 입력 ###########################################################
N, M, P, C, D = map(int, input().split(" "))
rr, rc = map(int, input().split(" "))

santas = []
santa_status = [0] * P # -(퇴장라운드), 0, +(기절) 퇴장, 정상, 기절
santa_score = [0] * P # score

for _ in range(P) :
    santas.append(list(map(int, input().split(" "))))
santas.sort(key = lambda x : x[0])
santas = [s[1:] for s in santas] # santas [sr, sc]이고 1번부터 P까지 순서대로 있음
######################################################################

for m in range(1, M+1) : # 1번-M번 턴, 남은 산타에 대해서만 +1점
    # 기절 산타들 풀어주기
    for i in range(P) :
        if santa_status[i] > 0 :
            santa_status[i] -= 1
    # 루돌프 이동, 산타와 가까워지는 방향으로
    sidx, dx, sr, sc = get_distance_from_r()  # d_list에서 산타 존재하면, 충돌!
    dr = (sr - rr) / abs(sr - rr) if rr - sr != 0 else 0
    dc = (sc - rc) / abs(sc - rc) if rc - sc != 0 else 0
    rr = rr + dr
    rc = rc + dc
    # 충돌 발생
    if [rr, rc] in santas :
        santa_score[sidx] += C
        tsr, tsc = santas[sidx][0] + dr * C, santas[sidx][1] + dc * C # 루돌프 이동 방향으로 C칸 물러남
        if 1 <= tsr <= N and 1 <= tsc <= N : # 범위내 있으면 산타 index 변경, 기절 상태로 변경
            santa_status[sidx] = 2
            push_santa(tsr, tsc, dr, dc, sidx)
        else : # 탈락 라운드 작성(나중에 점수에 +하면 됨), 근데 기절상태라면,,? <0일때만 +로 바꿔주는 함수 넣기
            santas[sidx] = [-N, -N] # 존재하지 않는 위치로 변경
            santa_status[sidx] = -m

    # 산타 거리 계산 후 이동 ###########################3
    # 산타 거리 계산할 때...상우하좌
    for sidx in range(P):
        if santa_status[sidx] == 0: # 정상일 때만 이동
            sr, sc = santas[sidx]
            condi_list = get_distance_from_s(sr, sc)
            mr, mc = 0, 0
            for condi in condi_list :
                _, _, dr, dc = condi
                if [sr+dr, sc+dc] not in santas :
                    mr, mc = dr, dc # 이동 확정
                    break
            # 산타 이동
            sr, sc = sr + mr, sc + mc
            if [sr, sc] == [rr, rc] : # 루돌프와 충돌 발생 확인, 루돌프는 반드시 map 범위 안에 있으니 추가 검사 필요하지 않음
                santa_score[sidx] += D
                tsr, tsc = sr + mr * (-D), sc + mc * (-D)
                santa_status[sidx] = 2 # 기절
                push_santa(tsr, tsc, -mr, -mc, sidx)
            else :
                santas[sidx] = [sr, sc]

    if max(santa_status) < 0 :
        break

# 출력 #############################################
for sidx in range(P) :
    if santa_status[sidx] < 0 : # 탈락 산타만 탈락 라운드 점수 더해주기
        santa_score[sidx] -= (santa_status[sidx]+1)
    else :
        santa_score[sidx] += M # 탈락하지 않은 산타는 M 라운드 더해주고
    print(santa_score[sidx], end=" ")