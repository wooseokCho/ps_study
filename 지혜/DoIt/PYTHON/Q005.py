import sys

input = sys.stdin.readline
n, m = map(int, input().split())
A = list(map(int, input().split()))
S = [0] * n  #합배열
C = [0] * m  #같은 나머지의 인덱스를 카운트하는 리스트 # 나머지가 0,1,...,m-1 이니까 총 m개
answer = 0

S[0] = A[0]
for i in range(1, n):
  S[i] = S[i - 1] + A[i]

for i in range(n):
  remainder = S[i] % m  # 합배열의 모든 값의 %연산 수행
  if (remainder == 0):
    answer += 1
  C[remainder] += 1  #나머지가 같은 것들이 몇개씩인지 체크

for i in range(m):
  #나머지가 같은 인덱스 중 2개를 뽑는 경우의 수를 더하기
  if (C[i] > 1):
    answer += (C[i] * (C[i] - 1) // 2)  # 이건 그냥 조합 계산

print(answer)
