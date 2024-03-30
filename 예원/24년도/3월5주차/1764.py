n,m = map(int, input().split())
unheard = set()
unseen = set()
for _ in range(n):
    unheard.add(input())
for _ in range(m):
    unseen.add(input())
intersection = sorted(list(unheard & unseen))
print(len(intersection))
for i in intersection:
    print(i)