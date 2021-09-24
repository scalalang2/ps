import sys
from collections import deque
input = sys.stdin.readline

n, m = list(map(int, input().split()))
adj = [[] for _ in range(n+1)]
indegree = [0 for _ in range(n+1)]

for _ in range(m):
    u,v = list(map(int, input().split()))
    adj[u].append(v)
    indegree[v] += 1

queue = deque([])
ans = []
for i in range(1, n+1):
    if indegree[i] == 0:
        queue.append(i)

while len(queue) > 0:
    curr = queue.popleft()
    ans.append(str(curr))
    for el in adj[curr]: 
        indegree[el] -= 1
        if indegree[el] == 0:
            queue.append(el)

print(" ".join(ans))