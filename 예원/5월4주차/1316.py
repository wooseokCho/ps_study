N=int(input())
cnt=N
for i in range(N):    
    str=input()
    if (len(str)>=3 and cnt>0):
        for m in range(len(str)-2):
            a= str.find(str[m], m+2)
            if(a!=-1 and str[a]!=str[a-1]):
                cnt-=1
                break                  
print(cnt)
        
