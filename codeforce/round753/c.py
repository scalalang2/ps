import sys
from heapq import heappush, heappop
input = sys.stdin.readline

t = int(input())

_ans = []

for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    a.sort()

    heap = []
    ans = -10e9 - 1
    if a[0] < 0:
        ans = max(ans, a[0])
        for i in range(1, n):
            heappush(heap, a[i] - a[0])
    else:
        for i in range(n):
            heappush(heap, a[i])
    
    p = 0
    while(len(heap) > 0):
        v = heappop(heap)
        ans = max(ans, v - p)
        p += v - p

    _ans.append(ans)

for el in _ans:
    print(el)