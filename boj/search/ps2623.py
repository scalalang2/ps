import sys
from collections import deque
input = sys.stdin.readline

n, m = list(map(int, input().split()))
ans = []
adj = [[] for _ in range(n+1)]
indegree = [0 for _ in range(n+1)]

for _ in range(m):
    arr = list(map(int, input().split()))
    for i in range(1, len(arr)-1):
        adj[arr[i]].append(arr[i+1])
        indegree[arr[i+1]] += 1

queue = deque([])

for i in range(1, n + 1):
    if indegree[i] == 0:
        queue.append(i)

while len(queue) > 0:
    curr = queue.popleft()
    ans.append(curr)
    for el in adj[curr]:
        indegree[el] -= 1
        if indegree[el] == 0:
            queue.append(el)

if len(ans) != n:
    print(0)
else:
    for el in ans:
        print(el)