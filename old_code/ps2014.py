import sys
from heapq import heappush, heappop
from collections import defaultdict
input = sys.stdin.readline

N, K = list(map(int, input().split()))
arr = list(map(int, input().split()))
queue = []

# 소수를 모두 넣는다.
for el in arr:
    heappush(queue, el)

ans = 0
for i in range(K):
    ans = heappop(queue)
    for j in range(len(arr)):
        heappush(queue, ans * arr[j])

        if ans % arr[j] == 0:
            break

print(ans)