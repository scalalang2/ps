import sys
from collections import deque
input = sys.stdin.readline

n, m = [int(x) for x in input().split()]
dist = [sys.maxsize for _ in range(n+m+1)]
adj = [[] for _ in range(n+m+1)]

for i in range(m):
    arr = [int(x) for x in input().split()]
    for j in range(len(arr)-1):
        adj[arr[j]].append((n+i+1, 1))
        adj[n+i+1].append((arr[j], 0))

ans = -1
s, e = [int(x) for x in input().split()]

queue = deque([])
queue.append(s)
dist[s] = 0

while len(queue) > 0:
    curr= queue.popleft()

    for el in adj[curr]:
        nxt = el[0]
        cost = el[1]
        if dist[curr] + 1 < dist[nxt]:
            dist[nxt] = dist[curr] + cost
            if cost == 1:
                queue.append(nxt)
            else:
                queue.appendleft(nxt)

if s == e:
    print(0)
elif dist[e] == sys.maxsize:
    print(-1)
else:
    print(dist[e]-1)
