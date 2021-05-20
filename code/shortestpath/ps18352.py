import sys
from collections import deque
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

N, M, K, S = list(map(int, input().split()))

graph = [[] for _ in range(N+1)]
dist = [0 for _ in range(N+1)]

for _ in range(M):
    u, v = list(map(int, input().split()))
    graph[u].append(v)

queue = deque([])
queue.append(S)
while len(queue) > 0:
    x = queue.popleft()
    for el in graph[x]:
        if dist[el] != 0:
            continue
        dist[el] = dist[x] + 1
        queue.append(el)
    
found = False
for i in range(len(dist)):
    if dist[i] == K and i != S:
        print(i)
        found = True
if not found:
    print(-1)