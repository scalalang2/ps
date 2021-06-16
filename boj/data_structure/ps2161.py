import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
queue = deque([])
ans = []

for i in range(n):
    queue.append(i+1)

while len(queue) > 0:
    ans.append(str(queue.popleft()))
    if len(queue) == 0:
        break
    el = queue.popleft()
    queue.append(el)

print(' '.join(ans))