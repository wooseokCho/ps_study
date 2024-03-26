n = 1260
array = [500, 100, 50, 10]
count = 0
for coin in array:
    count += n // coin
    n%=coin
print(count)