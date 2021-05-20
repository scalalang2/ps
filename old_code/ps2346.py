# 5
# 3 2 1 -3 -1
from collections import deque
import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
queue = deque([])
ans = []

for i in range(len(arr)):
    queue.append((arr[i], i + 1))

while len(queue) > 0:
    d, i = queue[0]
    ans.append(i)
    queue.popleft()

    if d > 0:
        d -= 1

    while len(queue) > 0 and d != 0:
        if d > 0:
            el = queue.popleft()
            queue.append(el)
            d -= 1
        else:
            el = queue.pop()
            queue.appendleft(el)
            d += 1

print(' '.join(list(map(str,ans))))