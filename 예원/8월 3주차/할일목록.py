def solution(todo_list, finished):
    return [work for idx, work in enumerate(todo_list) if not finished[idx]]