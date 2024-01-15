# input
N = int(input())
K = int(input())
apples = []
for _ in range(K) :
    apples.append(list(map(int, input().split(" "))))
L = int(input())
rotate = []
for _ in range(L) :
    tmp = input().split(" ")
    rotate.append([int(tmp[0]), tmp[1]])

time = 0
now_x, now_y = 1, 1
snake = [[now_y, now_x]]
direction = "R"

direction_order = ['R', 'D', 'L', 'U']

while True :
    time += 1

    if direction == "R" :
        now_x += 1
    elif direction == "L" :
        now_x -= 1
    elif direction == "D" :
        now_y += 1
    elif direction == "U" :
        now_y -= 1

    # 종료 - 벽에 닿았을 때
    if now_y > N or now_y < 1 or now_x > N or now_x < 1 :
        print(time)
        break
    
    # 종료 - 꼬리에 닿을 때
    if [now_y, now_x] in snake :
        print(time)
        break

    snake.append([now_y, now_x])
    
    if snake[-1] in apples :
        # print("Eat Apple")
        index = apples.index(snake[-1])
        apples.pop(index)
    else :
        snake.pop(0)

    for r in rotate :
        if r[0] == time :
            # print("Roate")
            index = direction_order.index(direction)
            if r[1] == 'L' :
                direction = direction_order[index - 1]
            else :
                direction = direction_order[(index + 1) % 4] # list 범위 ㄴ
    # print(time)
    # print(snake)
    # input()