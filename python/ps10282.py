import sys
from heapq import heappush, heappop
input = sys.stdin.readline

INF = 10 ** 8
t = int(input())

for _ in range(t):
    n, d, c = [int(x) for x in input().split()]
    graph = [[] for _ in range(n+1)]
    visited = [False for _ in range(n+1)]
    cost_arr = [sys.maxsize for _ in range(n+1)]
    nodes = 0
    ret = 0

    for i in range(d):
        a, b, s = [int(x) for x in input().split()]
        graph[b].append((a, s))

    queue = []
    heappush(queue, (0, c))
    cost_arr[c] = 0

    while len(queue) > 0:
        dist, node = heappop(queue)

        for nxt, nxt_cost in graph[node]:
            if cost_arr[nxt] > dist + nxt_cost:
                cost_arr[nxt] = dist + nxt_cost
                heappush(queue, (dist + nxt_cost, nxt))

    for el in cost_arr:
        if el != sys.maxsize:
            nodes += 1
            ret = max(ret, el)
        
    print(nodes, ret)