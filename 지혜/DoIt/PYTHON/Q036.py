answer = 0
A= list(input().split("-"))

def mySum(i):
  sum = 0
  temp = i.split("+")
  for i in temp:
    sum+=int(i)
  return sum


for i in range(len(A)):
  temp = mySum(A[i])
  if i ==0:
    answer += temp 
  else:
    answer -= temp
  
print(answer)