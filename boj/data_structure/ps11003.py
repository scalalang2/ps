import sys
from heapq import heappush, heappop

input = sys.stdin.readline

n, l = list(map(int, input().split()))
arr = list(map(int, input().split()))
queue = []
ans = []

for i in range(n):
    heappush(queue, (arr[i], i))
    mv, mi = queue[0]
    while len(queue) > 0:
        if not (i-l+1 <= mi <= i):
            heappop(queue)
            if len(queue) > 0:
                mv, mi = queue[0]
        else:
            break
    ans.append(str(mv))

print(' '.join(ans))