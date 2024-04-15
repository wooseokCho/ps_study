n = int(input()) #IOI만들어주는 개수
m = int(input())
s = input()
cursor, count, result = 0,0,0
while cursor < (m-1):
    if s[cursor:cursor+3] == "IOI":
        count+=1
        cursor+=2
        if count == n:
            result+=1
            count-=1
    else: #"IOI"가 아니면
        cursor+=1
        count = 0
print(result)

