import sys
sys.setrecursionlimit(10 ** 8)
input = sys.stdin.readline

N, M = [int(x) for x in input().split()]
table = [[-1 for _ in range(M)] for _ in range(N)]
visited = [[0 for _ in range(M)] for _ in range(N)]
ans = 0
dydx = {
    'D': (1, 0),
    'U': (-1, 0),
    'L': (0, -1),
    'R': (0, 1)
}

NOT_VISITED = 0
SEARCHING   = 1
GO_TO_DEAD  = 2
HAS_CYCLE   = 3

for i in range(N):
    text = input().rstrip()
    for j in range(M):
        table[i][j] = text[j]

# 탐색
def dfs(y, x, cnt):
    global visited
    global ans

    if y < 0 or y >= N or x < 0 or x >= M:
        ans += cnt
        return GO_TO_DEAD
    
    if visited[y][x] == GO_TO_DEAD:
        ans += cnt
        return GO_TO_DEAD
    
    if visited[y][x] == HAS_CYCLE or visited[y][x] == SEARCHING:
        return HAS_CYCLE

    visited[y][x] = SEARCHING
    
    dy, dx = dydx[table[y][x]]
    nx = x + dx
    ny = y + dy

    visited[y][x] = dfs(ny, nx, cnt + 1)
    return visited[y][x]
    
for i in range(N):
    for j in range(M):
        if visited[i][j] == NOT_VISITED:
            dfs(i, j, 0)

print(ans)