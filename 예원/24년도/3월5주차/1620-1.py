def main():
    n, m = map(int, input().split())
    name_to_number = {}
    number_to_name = {}

    for i in range(1, n + 1):
        name = input()
        name_to_number[name] = i
        number_to_name[i] = name

    for _ in range(m):
        query = input()
        if query.isdigit():
            print(number_to_name[int(query)])
        else:
            print(name_to_number[query])

if __name__ == "__main__":
    main()
