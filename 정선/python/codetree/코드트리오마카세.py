L, Q = map(int, input().split(" ")) # 초밥 길이, 명령 수
sushis = {}
customers = {}
queries = []
names = []

class Query :
    def __init__ (self, cmd, t, x, name, n) :
        self.cmd = cmd
        self.t = t
        self.x = x
        self.name = name
        self.n = n

for _ in range(Q) :
    t, x, name, n = -1, -1, -1, -1
    cmd, *infos = input().split(" ")
    cmd = int(cmd)
    if cmd == 100 :
        t, x, name = infos
        t, x = map(int, [t, x])
    elif cmd == 200 :
        t, x, name, n = infos
        t, x, n = map(int, [t, x, n])
    else :
        t = int(infos[0])

    queries.append(Query(cmd, t, x, name, n))

    if cmd == 100 :
        if name not in sushis:
            sushis[name] = [queries[-1]]
        else:
            sushis[name].append(queries[-1])
    elif cmd == 200 :
        customers[name] = queries[-1]

# 초밥 제거 command 110, 사람 제거 210
for name in sushis.keys() : # name
    customer = customers[name]

    time = 0
    last_time = 0
    sushis[name].sort(key=lambda x : x.t)
    for sushi in sushis[name] :
        if sushi.t < customer.t : # 초밥이 더 빨리 들어온 경우
            sushi_x = (customer.t - sushi.t + sushi.x) % L
            time = customer.t
        else : # 초밥이 더 늦게 들어온 경우
            sushi_x = sushi.x
            time = sushi.t

        time = time + (L + customer.x - sushi_x) % L
        last_time = max(time, last_time)

        queries.append(Query(110, time, -1, -1, -1)) # 초밥 out
    # queries.append(Query(220, time, -1, -1, -1)) # 사람 out
    queries.append(Query(220, last_time, -1, -1, -1)) # 사람 out

queries.sort(key=lambda q: (q.t, q.cmd))

people_num, sushi_num = 0, 0
for i in range(len(queries)):
    # print(queries[i].cmd, queries[i].t)
    if queries[i].cmd == 100:  # 초밥 추가
        sushi_num += 1
    elif queries[i].cmd == 110:  # 초밥 제거
        sushi_num -= 1
    elif queries[i].cmd == 200:  # 사람 추가
        people_num += 1
    elif queries[i].cmd == 220:  # 사람 제거
        people_num -= 1
    else:  # 사진 촬영시 답을 출력하면 됩니다.
        print(people_num, sushi_num)
