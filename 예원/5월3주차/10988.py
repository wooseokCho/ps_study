str=list(input())
reverse_str = str[::-1]
total=len(str)
b=total//2
print(1) if (str[:b] == reverse_str[:b]) else print(0)

        