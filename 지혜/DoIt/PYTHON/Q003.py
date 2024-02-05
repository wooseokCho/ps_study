#구간합 !!!!


import sys
input = sys.stdin.readline

N, M = map(int, input().split())
Arr = list(map(int, input().split()))
sumArr = [0]  #합배열 #0인 요소가 인덱스 0에 존재
temp = 0  #합배열을 만들기 위한 변수
for i in Arr:  # 합배열
  temp = i + temp
  sumArr.append(temp)


for _ in range(M):
  s, e = map(int, input().split())
  print(sumArr[e] - sumArr[s - 1])


# 파이썬 시간을 줄일 수 있는법
# https://simsim231.tistory.com/157
# 1. input() 보다는 sys.readline()
# 2. 빈 리스트에 append()로 추가하는 것 보단 입력 받을 개수 만큼 포기화된 리스트에 인덱스를 이용하여 접근해서 그 위치에 입력받자
# 3. 줄바꿈 할때엔 print()가 아니라 '/n' , for문 마다 출력하지 말고 문자열 변수에 저장해놓고 한번에 출력하자