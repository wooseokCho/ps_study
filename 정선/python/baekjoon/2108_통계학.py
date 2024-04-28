# 첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
# 둘째 줄에는 중앙값을 출력한다.
# 셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
# 넷째 줄에는 범위를 출력한다.
import sys
n = int(input())
nums = []
for _ in range(n) :
    nums.append(int(int(sys.stdin.readline())))

l = len(nums)
sorted_nums = sorted(nums)

# 최빈값 -> dictionary로 개수 저장해서 max value만 돌고 sort해서 두번 째 작은값 출력
tmp_n = sorted_nums[0]
counts = {tmp_n : 1}
maximum = 0
for n in sorted_nums[1:] :
    if tmp_n == n :
        counts[n] += 1
    else :
        if maximum < counts[tmp_n] :
            maximum = counts[tmp_n]
        tmp_n = n
        counts[n] = 1
        
if maximum < counts[sorted_nums[-1]] :
    maximum = counts[tmp_n]

candis = []
for n, cnt in counts.items() :
    if cnt == maximum :
        candis.append(n)
candis.sort()

# print(counts)
print(round(sum(nums) / l))
print(sorted_nums[l//2])
print(candis[0] if len(candis) == 1 else candis[1])
print(max(nums)-min(nums))