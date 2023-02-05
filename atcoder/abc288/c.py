import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
adj = [[] for _ in range(N+1)]
visited = [False for _ in range(N+1)]

for i in range(M):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

def bfs(st):
    if visited[st]:
        return 0

    queue = deque([st])
    visited[st] = True
    line = 0
    while len(queue) > 0:
        u = queue.popleft()
        for v in adj[u]:
            if not visited[v]:
                line += 1
                visited[v] = True
                queue.append(v)

    return line

ans = 0
for i in range(1, N+1):
    ans += bfs(i)

print(M-ans)