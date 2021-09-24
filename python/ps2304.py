# 결국 계단식 모양을 유지해야 한다.
import sys
input = sys.stdin.readline

n = int(input())
rect = [0 for _ in range(1001)]
arr = []

for _ in range(n):
    x, height = list(map(int, input().split()))
    rect[x] = height

lstack = []
rstack = []

for i in range(0, 1001):
    if rect[i] == 0:
        continue

    if len(lstack) == 0:
        lstack.append(i)
    else:
        if rect[lstack[len(lstack)-1]] <= rect[i]:
            lstack.append(i)

for i in range(1000, -1, -1):
    if rect[i] == 0:
        continue

    if len(rstack) == 0:
        rstack.append(i)
    else:
        if rect[rstack[len(rstack)-1]] <= rect[i]:
            rstack.append(i)

ans = 0
for i in range(1, len(lstack)):
    ans += (lstack[i] - lstack[i-1]) * rect[lstack[i-1]]

for i in range(1, len(rstack)):
    if lstack[len(lstack)-1] >= rstack[i-1]:
        break
    ans += (rstack[i-1] - rstack[i]) * rect[rstack[i-1]]

ans += rect[lstack[len(lstack)-1]]
print(ans)