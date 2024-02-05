# https://www.acmicpc.net/problem/12100

direction = ['U', 'D', 'L', 'R']
total_max = []
# input
N = int(input())
MAP = []

for _ in range(N) :
    MAP.append(list(map(int, input().split(" "))))

def print_map(mmap) :
    for m in mmap :
        print(" ".join(map(str, m)))

def move_and_merge_blocks(direction, mmap) :
    # print(direction)
    # print_map(mmap)
    n_mmap = []

    if direction == 'U' or direction == 'D' :
        mmap = [list(x) for x in zip(*mmap)] # transpose

    for m in mmap :
        while 0 in m :
            m.remove(0) # move
        if direction == 'R' or direction == 'D' :
            m.reverse()

        nm = [] # new_map
        flag = False
        for i in range(len(m)-1) :
            if flag :
                flag = False
                continue
            if m[i] == m[i+1] :
                nm.append(m[i]*2)
                flag = True
            else :
                nm.append(m[i])
        if len(m) != 0 and not flag:
            nm.append(m[-1])
        while len(nm) != N:
            nm.append(0)

        if direction == 'R' or direction == 'D' :
            nm.reverse()
        n_mmap.append(nm)

    if direction == 'U' or direction == 'D'  :
        n_mmap = [list(x) for x in zip(*n_mmap)]

    # print(">> AFTER")
    # print_map(n_mmap)
    # input()
    return n_mmap

def max_value(mmap) :
    max_v = 0
    for m in mmap :
        if max_v < max(m) :
            max_v = max(m)
    return max_v

def recursive_move(mmap, cnt) :
    if cnt >= 5 :
        total_max.append(max_value(mmap))
        return
    for d in direction :
        recursive_move(move_and_merge_blocks(d, mmap), cnt+1)

recursive_move(MAP, 0)
print(max(total_max))