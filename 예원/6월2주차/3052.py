my_list=[0 for i in range(42)]
for _ in range(10):
    num = int(input()) % 42
    if my_list[num] == 0:
        my_list[num] = 1
print(my_list.count(1))

