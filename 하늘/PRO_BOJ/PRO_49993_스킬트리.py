 
def solution(skill, skill_trees):
    skill_case =[]
    for i in range(len(skill)): # 0,1,2
        skill_case.append(skill[0:i+1])  

    lst = [] 
    for s in skill_trees:
        string = ''
        for w in s:
            if w in skill:
                string+= w
        lst.append(string)

    cnt = 0
    for l in lst:
        if l =='':
            cnt+=1
        if l in skill_case:
            print(l)
            cnt+=1
 
            
    return cnt
