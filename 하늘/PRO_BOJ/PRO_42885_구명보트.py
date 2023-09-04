from collections import deque

def solution(people, limit):
    result = 0
    deque_people = deque(sorted(people))

    while deque_people:  

        left = deque_people.popleft()
        if not deque_people:
            return result + 1

        right = deque_people.pop()
        if left + right > limit:
            deque_people.appendleft(left)

        result += 1
    return result
