import sys
sys.setrecursionlimit(2 * (10**5) + 1)
input = sys.stdin.readline

n, m = map(int, input().split())
G = [[] for _ in range(n+1)]
ind = [0 for _ in range(n+1)]
visited = [False for _ in range(n+1)]

for _ in range(m):
    u,v = map(int, input().split())
    G[u].append(v)
    G[v].append(u)
    ind[u] += 1
    ind[v] += 1

def dfs(node):
    visited[node] = True
    num_vertex = 1
    num_edge = ind[node]
    for nxt in G[node]:
        if not visited[nxt]:
            ve, ed = dfs(nxt)
            num_vertex += ve
            num_edge += ed

    return num_vertex, num_edge

ok = True
for i in range(1, n+1):
    if not visited[i]:
        vertex, edge = dfs(i)
        if vertex != edge//2:
            ok = False
            break

if ok:
    print("Yes")
else:
    print("No")