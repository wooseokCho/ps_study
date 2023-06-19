N=int(input())
i=0
while(i>=0):
    if N<=3*(i+1)*i+1:
        break
    i+=1   
print(i+1)
