import sys
input = sys.stdin.readline

equa = list(map(str, input().split("-")))
total = 0
for i, val in enumerate(equa):
    temp_list = list(map(int, val.split("+")))
    if i == 0:
        total += sum(temp_list)
        continue
    total -=sum(temp_list)
print(total)