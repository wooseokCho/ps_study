from collections import defaultdict
test_case = int(input())
for _ in range(test_case):
    my_dict = defaultdict(int)
    n=int(input())
    for i in range(n):
        name, cate = input().split()
        my_dict[cate] +=1
    result = 1
    for value in my_dict.values():
        result*=(value+1)
print(result-1)

