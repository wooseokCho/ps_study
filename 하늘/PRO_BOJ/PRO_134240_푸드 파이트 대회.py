def solution(food):
    answer = '' 
    food2 = []
    for i in food:
        food2.append(i//2)

        
    for j in range(len(food2)):
        if j >=1 :
            for _ in range(food2[j]):
                answer += str(j)
                
    answer+=str(0)
   
    answer2=''
    
    for s in range(len(answer)):
        answer2+= answer[len(answer)-int(s)-1]  
    answer2 = answer2[1:]
    answer +=answer2
        
        
    return answer
