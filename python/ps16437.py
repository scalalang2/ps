import sys
sys.setrecursionlimit(123458)

input = sys.stdin.readline

N       = int(input())
adj     = [[] for _ in range(N+1)]
sheeps  = [[0, 0] for _ in range(N+1)]
root    = 1
SHEEP   = "S"
WOLF    = "W"

for i in range(2, N+1):
    t, a, p  = [x for x in input().split()]
    adj[int(p)].append(i)
    sheeps[i][0] = t
    sheeps[i][1] = int(a)

sheeps[root][0] = SHEEP
sheeps[root][1] = 0

def dfs(node):
    sheep = 0

    for nxt in adj[node]:
        sheep += dfs(nxt)
        
    if sheeps[node][0] == WOLF:
        if sheep < sheeps[node][1]:
            sheeps[node][1] -= sheep
            sheep = 0
        else:
            sheep -= sheeps[node][1]
            sheeps[node][1] = 0
    else:
        sheep += sheeps[node][1]
        sheeps[node][1] = 0

    return sheep

print(dfs(root))