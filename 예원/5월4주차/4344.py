C=int(input())
for i in range(C):
    aver=0
    cnt=0
    ratio=0
    sum=0
    scorelist=list(map(int, input().split()))
    score=scorelist[1:]
    num=scorelist[0]
    for i in range(1, len(scorelist)):
        sum+=scorelist[i]
    aver=sum/num
    for m in score:
        if (m>aver):
            cnt+=1
    ratio = (cnt/num)*100
    print(f'{ratio:.3f}%')

