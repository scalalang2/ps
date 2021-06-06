import sys
from heapq import heappush, heappop
input = sys.stdin.readline

n, k = list(map(int, input().split()))
ans = 0
# 무게 기준 최소 힙
weights = []

# 가치 기준 최대 힙
values = []

bags = []

for _ in range(n):
    w, v = list(map(int, input().split()))
    heappush(weights, (w, v))

for _ in range(k):
    bags.append(int(input()))
bags.sort()

for b in bags:
    while True:
        if len(weights) == 0:
            break
        w, v = heappop(weights)
        if w > b:
            heappush(weights, (w, v))
            break
        heappush(values, (v * -1, w))
    if len(values) > 0:
        v, w = heappop(values)
        ans += v * -1

print(ans)