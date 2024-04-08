# 문제 제대로 읽기, 숫자 위치는 바뀌면 안되는거...
# for 문 위치 잘 생각하기
# 순열 -> 재귀 사용, append, pop 함수 argument로 주면 안됨
# 순열의 경우 완전탐색으로 시간 초과 날 수 있음
# 백트래킹? 순열? 뭔차인거지?
# deepcopy 대신 [:] 사용하기
# 10억 1000000000 1포함 10
N = int(input())
nums = list(map(int, input().split(" ")))
opers = list(map(int, input().split(" "))) # +, -, *, /

def change_opers_format(opers) :
    op_order = ["+", "-", "*", "/"]
    new_opers = []
    for i, op in enumerate(opers) :
        new_opers.extend([op_order[i]] * op)
    return new_opers

def get_permutation(nums, tmp, len_nums) :
    if len(tmp) == len_nums:
        permutations.append(tmp)
        return 

    for i, n in enumerate(nums) :
        nnums = nums[:]
        ntmp = tmp[:]
        nnums.pop(i)
        ntmp.append(n)
        get_permutation(nnums, ntmp, len_nums)

def get_permutation_without_duplication(mylist) :
    global permutations
    permutations = []
    get_permutation(mylist, [], len(mylist)) 
    permutations = list(set(map(tuple, permutations))) 
    return permutations[:]

def calcuate(x1, x2, op) :
    # / 시 int 형인지, 음수 / 잘 되는지 확인 필요
    if op == '+' : return x1 + x2
    elif op == '-' : return x1 - x2
    elif op == '*' : return x1 * x2
    elif op == '/' : return int(x1 / x2)

def get_result(num, op_perms) :
    min_v = 1000000000
    max_v = -1000000000
    for op in op_perms :
        tmp = int(num[0])
        for idx in range(1, N) :
            tmp = calcuate(tmp, int(num[idx]), op[idx-1])

        if min_v > tmp : 
            min_v = tmp
        if max_v < tmp :
            # print(f"{dbg_string} = {tmp}") 
            max_v = tmp
        # print(min_v, max_v)
    return min_v, max_v

opers = change_opers_format(opers) 
op_perms = get_permutation_without_duplication(opers)
min_v, max_v = get_result(nums, op_perms)
print(max_v)
print(min_v)