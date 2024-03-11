n = int(input())
data = list(map(int, input().split()))
data.sort()

count = 0#그룹에 있는 모험가 수
result = 0 #만들어지는 그룹 수

for i in data:
    count +=1
    if count>=i:
        result+=1
        count= 0

print(count)