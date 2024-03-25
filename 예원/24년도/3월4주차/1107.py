target = int(input())
ans = abs(100-target)
M=int(input())
if M:
    broken = set(input().split())
else:
    broken = set(input().split())
for num in range(1000001):
    for N in str(num):
        if N in broken: #해당 숫자가 번호를 눌러서 나올 수 없는 경우, 스탑
            break
    else:#번호를 눌러서 만들 수 있는 경우엔
        #(기존답, 번호를 누른 횟수+해당 번호로부터 타겟까지의 차이)
        ans = min(ans, len(str(num))+abs(num-target))
print(ans)
