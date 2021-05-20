import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
arr.sort()

acc = 0
ret = 0

for i in range(N):
    if acc + 1 < arr[i]:
        ret = acc + 1
        break
    else:
        acc += arr[i]

# 누적은 되었지만 ret가 갱신되지 않았다면
if acc != 0 and ret == 0:
    ret = acc + 1

print(ret)