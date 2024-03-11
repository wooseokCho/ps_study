a,b,c = map(int,input().split())

def gcd(a,b):
  if b==0:
    return a
  else:
    return gcd(b,a%b)
  
def Execute(a,b):
  ret = [0]*2
  if b == 0:
    ret[0] =1
    ret[1] = 0
    return ret
  q = a//b
  v = Execute(b, a%b)
  ret[0] = v[1]
  ret[1] = v[0] - v[1]*q
  return ret

mgcd = gcd(a,b)

if c%mgcd !=0:
  print(-1)
else:
  mok = int(c/mgcd)
  ret = Execute(a,b)
  print(ret[0]* mok,end=" ")
  print(ret[1]*mok)