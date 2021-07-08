import sys
from heapq import heappush, heappop
from collections import deque

input = sys.stdin.readline

# 풀이를 봤다
# 1. 다익스트라를 돌면서 출발 지점으로부터 모든 노드까지의 최단경로를 계산하여 dist에 삽입한다.
# 2. 최종 노드로부터 하나씩 pop하면서 최단 경로에 해당하는 간선을 제거한다.
# 3. 다시 다익스트라를 수행한다.

MAX = 501
d = [[-1 for _ in range(MAX)] for _ in range(MAX)]
dist = [sys.maxsize for _ in range(MAX)]
ans = []

def dijkstra(st):
    global d
    global dist

    dist = [sys.maxsize for _ in range(MAX)]

    queue = []
    heappush(queue, (0, st))
    dist[st] = 0

    while len(queue) > 0:
        cost, node = heappop(queue)

        for i in range(MAX):
            if d[node][i] == -1:
                continue
            if dist[i] > cost + d[node][i]:
                dist[i] = cost + d[node][i]
                heappush(queue, (dist[i], i))

def remove_edges(ed):
    global d
    global dist

    queue = deque([])
    queue.append(ed)

    while len(queue) > 0:
        node = queue.popleft()
        for i in range(MAX):
            if d[i][node] == -1:
                continue
            if dist[node] == dist[i] + d[i][node]:
                d[i][node] = -1
                queue.append(i)

while True:
    N, M = [int(x) for x in input().split()]
    if N == 0 and M == 0:
        break
    S, D = [int(x) for x in input().split()]
    d = [[-1 for _ in range(MAX)] for _ in range(MAX)]

    for _ in range(M):
        u, v, p = [int(x) for x in input().split()]
        d[u][v] = p

    dijkstra(S)
    remove_edges(D)
    dijkstra(S)

    if dist[D] == sys.maxsize:
        ans.append(-1)
    else:
        ans.append(dist[D])

for el in ans:
    print(el)
