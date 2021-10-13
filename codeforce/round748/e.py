import sys
from collections import deque
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    input()
    n, k = list(map(int, input().split()))
    indegree = [0 for _ in range(n+1)]
    adj = [[] for _ in range(n+1)]
    chk = [False for _ in range(n+1)]
    for _ in range(n-1):
        u, v = list(map(int, input().split()))
        indegree[u] += 1
        indegree[v] += 1
        adj[u].append(v)
        adj[v].append(u)
        chk[u] = True;
        chk[v] = True;
    
    queue = deque([])
    for i in range(1, n+1):
        if chk[i] and indegree[i] == 1:
            queue.append(i)

    cut_nodes = 0
    for _ in range(k):
        # print(chk)
        # print(indegree)
        nq = deque([])

        while(len(queue) > 0):
            curr = queue.pop()
            chk[curr] = False;
            indegree[curr] -= 1
            cut_nodes += 1
            for nxt in adj[curr]:
                if chk[nxt]:
                    indegree[nxt] -= 1
                    if indegree[nxt] == 1:
                        nq.append(nxt)
        queue = nq
    print(sum(chk))