import sys
from collections import deque
input = sys.stdin.readline

k = int(input())
W, H = [int(x) for x in input().split()]
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

_dx2 = [1, 1, -1, -1, 2, 2, -2, -2]
_dy2 = [2, -2, 2, -2, 1, -1, 1, -1]

table = []

for i in range(H):
    table.append([int(x) for x in input().split()])

dist = [[[sys.maxsize for _ in range(k+1)] for _ in range(W)] for _ in range(H)]
queue = deque([])
queue.append((0, 0, 0))
dist[0][0][0] = 0

while len(queue) > 0:
    y, x, cnt = queue.popleft()

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        
        if ny < 0 or ny >= H or nx < 0 or nx >= W:
            continue

        if table[ny][nx] == 1:
            continue
        
        if dist[ny][nx][cnt] != sys.maxsize:
            continue

        dist[ny][nx][cnt] = min(dist[ny][nx][cnt], dist[y][x][cnt] + 1)
        queue.append((ny, nx, cnt))
    
    if cnt >= k:
        continue

    for i in range(8):
        ny = y + _dy2[i]
        nx = x + _dx2[i]

        if ny < 0 or ny >= H or nx < 0 or nx >= W:
            continue

        if table[ny][nx] == 1:
            continue
        
        if dist[ny][nx][cnt+1] != sys.maxsize:
            continue

        dist[ny][nx][cnt+1] = min(dist[ny][nx][cnt+1], dist[y][x][cnt] + 1)
        queue.append((ny, nx, cnt + 1))

ans = sys.maxsize
for i in range(k+1):
    ans = min(dist[H-1][W-1][i], ans)

if ans == sys.maxsize:
    print(-1)
else:
    print(ans)