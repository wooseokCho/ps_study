import sys
from collections import deque

input = sys.stdin.readline

N,M,K,X = map(int,input().split())
A = [[] for _ in range(N+1)] #[[],[],[],[],[]]
answer = []
vistited = [-1] *N+1 #시작노드는 0 이므로 -1로 초기화

def BFS(v):
  queue = deque()
  queue.append(v)  # 시작노드 삽입 
  vistited[v] += 1 # 현재노드 방문 기록
  while queue:
    now_Node = queue.popleft()

    for i in A[now_Node]:
      if vistited[i] == -1:
        vistited[i] = vistited[now_Node] +1
        queue.append(i) 


for _ in range(M):
  S,E = map(int ,input().split())
  A[S].append(E)

BFS(X)

for i in range(N+1): #방문 거리가 K인 노드의 숫자를 정답 리스트에 더하기
  if vistited[i] == K:
    answer.append(i)

if not answer: 
  print(-1)
else: # 정답 리스트 오른차순 정렬 후 순차 출력
  answer.sort()
  for i in answer:
    print(i)