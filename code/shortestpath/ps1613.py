import sys
input = sys.stdin.readline

n, t = list(map(int, input().split()))

path = [[False for _ in range(n+1)] for _ in range(n+1)]

for _ in range(t):
    u, v = list(map(int, input().split()))
    path[u][v] = True

for k in range(n+1):
    for i in range(n+1):
        for j in range(n+1):
            if path[i][k] and path[k][j]:
                path[i][j] = True

s = int(input())
for _ in range(s):
    u, v = list(map(int, input().split()))
    if not (path[u][v] or path[v][u]):
        print(0)
    elif path[u][v]:
        print(-1)
    else:
        print(1)