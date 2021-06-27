import sys
from heapq import heappush, heappop
input = sys.stdin.readline

# 중앙 값을 기준으로 양분해야 하니 최대힙 최소힙으로 나누어야 한다.
n = int(input())
minheap = []
maxheap = []
ans = []

def swap():
    if maxheap[0] * -1 > minheap[0]:
        a = heappop(maxheap) * -1
        b = heappop(minheap)
        heappush(maxheap, b * -1)
        heappush(minheap, a)


for i in range(n):
    x = int(input())
    if i == 0:
        heappush(maxheap, x * -1)
        ans.append(x)
    elif i == 1:
        heappush(minheap, x)
        swap()
        ans.append(min(minheap[0], maxheap[0] * -1))
    else:
        if len(maxheap) == len(minheap):
            heappush(maxheap, x * -1)
            swap()
            ans.append(maxheap[0] * -1)
        else:
            heappush(minheap, x)
            swap()
            ans.append(maxheap[0] * -1)

for el in ans:
    print(el)