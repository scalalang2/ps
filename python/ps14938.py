import sys
from collections import deque
input = sys.stdin.readline

MAX = 10 ** 10
n, m, r = list(map(int, input().split()))
items = list(map(int, input().split()))
graph = [[MAX for _ in range(n)] for _ in range(n)]
answer = 0

for i in range(r):
    u, v, c = list(map(int, input().split()))
    graph[u-1][v-1] = c
    graph[v-1][u-1] = c

for k in range(n):
    for i in range(n):
        for j in range(n):
            if graph[i][j] > graph[i][k] + graph[k][j]:
                graph[i][j] = graph[i][k] + graph[k][j]

for i in range(n):
    n_of_items = items[i]
    for j in range(n):
        if graph[i][j] <= m and i != j:
            n_of_items += items[j]
    answer = max(answer, n_of_items)

print(answer)