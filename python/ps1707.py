import sys
from collections import deque
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    V, E = list(map(int, input().split()))
    graph = [[] for _ in range(V+1)]
    chk = [0 for _ in range(V + 1)]
    ret = True

    def bfs(node):
        global chk 

        queue = deque([])
        chk[node] = 1
        queue.append(node)

        while len(queue) > 0:
            nxt = queue.popleft()
            color = 2 if chk[nxt] == 1 else 1
            for v in graph[nxt]:
                if chk[v] == 0:
                    chk[v] = color
                    queue.append(v)

    for _ in range(E):
        u, v = list(map(int, input().split()))
        graph[u].append(v)
        graph[v].append(u)

    for u in range(1, V + 1):
        if chk[u] == 0:
            bfs(u)
    
    for u in range(1, V+1):
        for v in graph[u]:
            if chk[u] == chk[v]:
                ret = False
    
    if ret:
        print("YES")
    else:
        print("NO")
