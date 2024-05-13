import sys
input= sys.stdin.readline
m = int(input())
s = set()
for _ in range(m):
    command_parts = input().split()
    if len(command_parts) == 2: 
        command, x = command_parts[0], int(command_parts[1])
        if command == "add":
            s.add(x)
        if command == "remove":
            s.discard(x)
        if command == "check":
            if x in s:
                print(1)
            else:
                print(0)
        if command == "toggle":
            if x in s:
                s.remove(x)
            else:
                s.add(x)
    else: 
        command2 = command_parts[0]
        if command2 == "all":
            s = set(i for i in range(1,21))
        if command2 == "empty":
            s.clear()