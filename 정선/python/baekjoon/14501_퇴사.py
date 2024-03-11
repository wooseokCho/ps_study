# 입력 받기
N = int(input())

days = []
moneys = []

for _ in range(N) :
    d, m = input().split(" ") # day, money
    days.append(int(d))
    moneys.append(int(m))
    
max_money = 0

def recusive_work(d, t_m) : # day, total_money
    global max_money 
    
    if d+1 >= N :
        if max_money < t_m :
            max_money = t_m
    else :
        recusive_work(d+1, t_m)

    if d+days[d] >= N :
        if d+days[d] == N :
            t_m += moneys[d]
        if max_money < t_m :
            max_money = t_m
    else :
        recusive_work(d+days[d], t_m+moneys[d])

recusive_work(0, 0)
print(max_money)