N,M=map(int, input().split())
my_list=[(i+1) for i in range(N)]
for _ in range(M):
    a,b=map(int, input().split())
    my_list[0:N] = my_list[0:a-1] + my_list[a-1:b-1][::-1] + my_list[b-1:N]
for i in my_list:
    print(i, end=' ')