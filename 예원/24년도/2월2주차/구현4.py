data = input()
result = []
value = 0

for d in data:
    if d.isalpha():
        result.append(d)
    else:
        value+=int(d)
result.sort()
if value!=0:
    result.append(str(value))

print("".join(result))