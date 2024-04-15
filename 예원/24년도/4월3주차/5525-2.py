n = int(input())
m = int(input())
s=input()
cursor, count, result = 0,0,0
while cursor <(m-1):
    if s[cursor:cursor+3] == "IOI":
        cursor+=2
        count+=1
        if count == n:
            result+=1
            count-=1
    else:
        count = 0
        cursor+=1
print(result)