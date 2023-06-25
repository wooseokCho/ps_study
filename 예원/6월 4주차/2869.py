A,B,V=map(int, input().split())
k=(V-B)/(A-B)
print(int(k) if k==int(k) else int(k)+1)
