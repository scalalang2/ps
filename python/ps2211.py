import sys
from heapq import heappush, heappop
input = sys.stdin.readline

N, M = [int(x) for x in input().split()]
super_node = 1

adj = [[] for _ in range(N+1)]
cost = [sys.maxsize for _ in range(N+1)]
path = [-1 for _ in range(N+1)]

for _ in range(M):
    A, B, C = [int(x) for x in input().split()]
    adj[A].append((B, C))
    adj[B].append((A, C))

def dijkstra(curr):
    global cost
    global path
    queue = []
    heappush(queue, (0, curr))

    while len(queue) > 0:
        c, node = heappop(queue)

        for nxt, dist in adj[node]:
            if cost[nxt] > c + dist:
                cost[nxt] = c + dist
                path[nxt] = node
                heappush(queue, (cost[nxt], nxt))
        

cost[super_node] = 0
dijkstra(super_node)

print(N-1)
for i in range(2, N+1):
    print(i, path[i])
