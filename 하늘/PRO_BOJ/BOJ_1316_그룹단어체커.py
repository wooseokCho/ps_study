n = int(input()) 
word_lst = [str(input()) for _ in range(n)]

answer = 0
for string in word_lst:
  lst = [string[0]]
  for s in string[1:]:
    if lst[-1] != s:
      lst.append(s) 
  if len(set([i for i in string])) == len(lst): 
    answer +=1 

print(answer)
