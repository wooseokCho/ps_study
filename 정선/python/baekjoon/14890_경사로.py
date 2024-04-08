# list transpose : list transpose [list(x) for x in zip(*mmap)]
# zip은 같은 index 요소들을 묶기 때문에, tuple unpacking 후 인덱스 별로 묶어줌
# Edge 케이스 잘 생각하기..
# range(N)에서 N는 포함되지 않는 것 주의
# 문제 완벽히 이해가 필요, 예시 기반으로 먼저 머리로 생각해서 원하는 답이 나오는지 확인 후 문제풀기
# for문 범위 주의하기

# 재귀 - 56ms ######################################################################
# 문제 이해를 잘못해서, 높은 곳에도 경사로를 둘 수 있다고 생각하여 재귀로 작성
# 재귀로 작성하지 않아도 풀이 가능
# def check_possible_road(vector, idx, put_ramp) :
#     global vector_result
#     if idx == N :
#         vector_result = True
#         return
#     diff = vector[idx] - vector[idx-1]
#     # print(idx, put_ramp, diff)
#     if abs(diff) > 1 :
#         return 
#     elif diff ==  1 : # 뒤에 있는 값이 1 크면, 앞에 경사로
#         if idx-L >= 0 :
#             for i in range(idx-L, idx) :
#                 if i in put_ramp :
#                     return 
#             # print(f"FRONT {[idx-L, idx-1]}")
#             check_possible_road(vector, idx+1, put_ramp+[x for x in range(idx-L, idx)])
       
#     elif diff == -1 : # 뒤에 있는 값이 1 작으면, 뒤에 경사로
#          if idx+L-1 < N :
#             be = vector[idx]
#             for i in range(idx+1, idx+L) :
#                 if be != vector[i] : 
#                     return 
#                 be = vector[i]
#             # print(f"BACK  {[idx, idx+L-1]}")
#             check_possible_road(vector, idx+L, put_ramp+[x for x in range(idx, idx+L)])
#     else :
#         check_possible_road(vector, idx+1, put_ramp)
# N, L = map(int, input().split(" "))
# mmap = []
# for _ in range(N) :
#     mmap.append(list(map(int, input().split(" ")))
# )
# result = 0
# for m in [mmap, zip(*mmap)] :
#     for vector in m :
#         vector_result = False
#         check_possible_road(vector, 1, [])
#         result += vector_result
#         # if vector_result :
#         #     print(vector)
# print(result)
######################################################################

# 재귀 X - 48ms ######################################################################
# 재귀 아닐 떄 종료 조건 잘 넣어주기
def check_possible_road(vector) :
    visited = [False] * len(vector)
    for i in range(1, len(vector)) :
        # print(i)
        # print(visited)
        diff = vector[i] - vector[i-1]
        if abs(diff) > 1 :
            return False
        if diff ==  1 : # 뒤에 있는 값이 1 크면, 앞에 경사로
            if i-L >= 0 :
                for j in range(i-L, i) :
                    if visited[j] :
                        return False
                    visited[j] = True
            else :
                return False
        if diff == -1 : # 뒤에 있는 값이 1 작으면, 뒤에 경사로
            if i+L-1 < N :
                be = vector[i]
                for j in range(i+1, i+L) :
                    if be != vector[j] : 
                        return False
                    be = vector[j]
                for j in range(i, i+L) :
                    visited[j] = True
            else :
                return False
    return True
# FOR DBG ############################################
# N, L = 6, 2
# mmap = [[3, 3, 3, 3, 3, 3],
#         [2, 3, 3, 3, 3, 3],
#         [2, 2, 2, 3, 2, 3],
#         [1, 1, 1, 2, 2, 2],
#         [1, 1, 1, 3, 3, 1],
#         [1, 1, 2, 3, 3, 2]]
# N, L = 6, 1
# mmap = [[3, 2, 2, 1, 2, 3]]
# result = 0
# for row in mmap :
#     print(row)
#     vector_result = False
#     check_possible_road(row, 1, row[0], [])
#     print(vector_result)
#######################################################

N, L = map(int, input().split(" "))
mmap = []
for _ in range(N) :
    mmap.append(list(map(int, input().split(" ")))
)
result = 0
for m in [mmap, zip(*mmap)] :
    for vector in m :
        # print()
        # if check_possible_road(vector) :
        #     print("SUCCESS")
        #     print(vector)
        result += check_possible_road(vector)
        # if check_possible_road(vector) :
print(result)