str=input()
result=0
for char in str:
    char = ord(char)
    if (char>=65 and char<=67):
        result+=3
    elif (char >= 68 and char <= 70):
        result+=4
    elif (char >= 71 and char <= 73):
        result+=5
    elif (char >= 74 and char <= 76):
        result+=6
    elif (char >= 77 and char <= 79):
        result+=7
    elif (char >= 80 and char <= 83):
        result+=8
    elif (char >= 84 and char <= 86):
        result+=9
    else:
        result+=10
print(result)