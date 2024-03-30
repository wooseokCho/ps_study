nums = input()
current_number = ""
result = 0
sign = 1
for i in nums:
    if i.isdigit():
        current_number+=i
    else:
        result+= sign * int(current_number)        
        if i == "-":
            sign = -1
        current_number = ""
result+= sign * int(current_number)   
print(result)
