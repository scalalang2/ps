# 접근 방법 
# min(1 -> v1 -> v2 -> N, 1 -> v2 -> v1 -> N)
import sys
from collections import deque
from heapq import heappush, heappop
input = sys.stdin.readline

MAX = 10 ** 10
N, E = list(map(int, input().split()))
ans = 0
graph = [[-1 for _ in range(N+1)] for _ in range(N+1)]
for _ in range(E):
    u, v, c = list(map(int, input().split()))
    graph[u][v] = c
    graph[v][u] = c

v1, v2 = list(map(int, input().split()))

def shortest_path(st, ed):
    queue = deque([st])
    dist = [MAX for _ in range(N+1)]
    dist[st] = 0

    while len(queue) > 0:
        curr = queue.popleft()
        for i in range(N+1):
            if graph[curr][i] != -1 and dist[i] > dist[curr] + graph[curr][i]:
                dist[i] = dist[curr] + graph[curr][i]
                queue.append(i)
    
    return dist[ed]

ans = min(
    shortest_path(1, v1) + shortest_path(v1, v2) + shortest_path(v2, N),
    shortest_path(1, v2) + shortest_path(v2, v1) + shortest_path(v1, N)
)

if ans >= MAX:
    print(-1)
else:
    print(ans)