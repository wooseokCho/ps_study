# N의 최댓값 = 10,000,000 -> O(N)의 시간복잡도인 투포인터 사용
import sys

input = sys.stdin.readline

N = int(input())

sum = 1
answer = 0
start = 1
end = 1

while (1):
  if (start == N):
    answer += 1
    break
  else:
    if (sum == N):
      answer += 1
      end += 1
      sum += end
    elif (sum > N):
      sum = sum - start
      start += 1
    else:
      end += 1
      sum += end


print(answer)