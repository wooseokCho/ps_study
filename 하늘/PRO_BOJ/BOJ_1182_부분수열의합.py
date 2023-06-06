
from itertools import combinations  

n,s =  map(int , input().split()) 
n_lst = list(map(int, input().split()))
cnt =0

for r in range(1, n+1):
  comb = combinations(n_lst, r)
  for x in comb:
    print(r, x)
    if sum(x) == s:
      cnt+=1
