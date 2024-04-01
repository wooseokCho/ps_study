# https://school.programmers.co.kr/learn/courses/30/lessons/84021
import copy
# 정렬하거나, 맞춰주는건 영향이 없으면 최종단에서 처리
# list min 사용법 정확히 알기, list 모양은 변하지 않음, 앞에서 원소의 최소 기준으로 작은 것 return
# for문 첫단, 끝단 처리 잘 정리해서 코드 짜기
# 2차원 리스트 정렬, part.sort(key=lambda x : (x[0], x[1])) -> 그럼 굳이 리스트 정렬 안 쓰고, 

def rotate_part(part) :
    length = max(max(part))
    
    rotated_part = copy.deepcopy(part)
    rotated_parts = []
    
    for i in range(4) :
        rotated_part = [[p[1], length - p[0] - 1] for p in rotated_part]
        rotated_parts.append(rotated_part)
    return rotated_parts

def abs_list(list1, list2) :
    return abs(list1[0] - list2[0]) + abs(list1[1] - list2[1])

def compare_part(part1, part2) :
    part1 = sort_n_shift_part(part1)
    part2 = sort_n_shift_part(part2)
    
    result = 0
    for idx in range(len(part1)) :
        result += abs_list(part1[idx], part2[idx])
        
    return True if result == 0 else False

def compare_part_with_rotate(part1, part2):
    rotated_parts2 = rotate_part(part2)
    for r_part2 in rotated_parts2 :
        if compare_part(part1, r_part2) :
            return True
    return False
    
def get_match_size(empty_parts, puzzle_parts) :
    match_size = 0
    matched = [False] * len(empty_parts)
    for p_part in puzzle_parts :
        for idx, e_part in enumerate(empty_parts) :
            if not matched[idx] and len(p_part) == len(e_part) :
                # print(p_part, e_part)
                if compare_part_with_rotate(p_part, e_part) :
                    # print(compare_part_with_rotate(p_part, e_part))
                    matched[idx] = True
                    match_size += len(p_part)
                    break
    return match_size                
                    

def sort_n_shift_part(part) :
    # 2차원 정렬(외우기), https://kingofbackend.tistory.com/98
    part.sort(key=lambda x : (x[0], x[1]))
    min_0, min_1 = 50, 50
    for p_0, p_1 in part :
        if min_0 > p_0 :
            min_0 = p_0
        if min_1 > p_1 :
            min_1 = p_1
            
    for element in part : 
        element[0] = element[0]-min_0
        element[1] = element[1]-min_1
    
    return part
    
def find_parts(board, value) : # empty : 0, table_part : 1
    locs = []
    # 빈 공간 모두 찾기
    for y_idx, line in enumerate(board) :
        for x_idx, v in enumerate(line) :
            if v == value :
                locs.append([y_idx, x_idx])
        
    # 이어진 것끼리 합쳐주기
    visited = [False] * len(locs)
    visited[0] = True
    queue = [locs[0]]
    
    tmp_part = []
    result_parts = []
    
    while (False in visited) or len(queue) != 0 :
        loc = queue.pop(0)
        tmp_part.append(loc)
        
        for idx, el in enumerate(locs) :
            if visited[idx] :
                continue
            if abs_list(el, loc) == 1 :
                queue.append(el)
                visited[idx] = True
        
        
        if len(queue) == 0 :
            result_parts.append(tmp_part)
            tmp_part = []
            try :
                v_idx = visited.index(False)
                queue = [locs[v_idx]] # vistied False
                visited[v_idx] = True
            except :
                queue = [] # vistied False
        
    return result_parts

            
def solution(game_board, table):
    empty_parts = find_parts(game_board, 0)
    puzzle_parts = find_parts(table, 1)
    
    return get_match_size(empty_parts, puzzle_parts)