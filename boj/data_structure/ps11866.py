import sys
from collections import deque
input = sys.stdin.readline

n, k = list(map(int, input().split()))
queue = deque([])

for i in range(n):
    queue.append(i+1)

ans = []
while len(queue) > 0:
    for i in range(k-1):
        queue.append(queue.popleft())
    ans.append(queue.popleft())

print('<' + ', '.join(list(map(str, ans))) + '>')