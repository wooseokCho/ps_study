from collections import Counter
str=input().upper()
if len(str) == 1:
    print(str)
else:
    count = Counter(str).most_common(2)
    if count[0][1] == count[1][1]:
        print("?")
    else:
        print(count[0][0])