
from collections import defaultdict

word = input()
word = word.upper()

dict = defaultdict()
lst = list(set(word))


for w in lst:
    dict[w] = word.count(w)
 
cnt=0
answer =''

for k, v in dict.items():
    if v == max(dict.values()): 
        cnt +=1
        answer = k

if cnt >1:
    print('?')
else:
    print(answer) 
