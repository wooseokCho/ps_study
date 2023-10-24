def solution(myString):
    tmp=[]
    splitted=myString.split("x")
    for i in splitted:
        if i != "":
            tmp.append(i)

    return sorted(tmp)