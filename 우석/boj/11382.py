def calculate_sum(input_string):
    numbers = input_string.split()

    total_sum = sum(int(num) for num in numbers)

    return total_sum

print(calculate_sum(input()))