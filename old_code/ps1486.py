# 접근 방법 
# - (0,0)에서 모든 (i,j)까지 최단 시간 계산
# - (i,j)에서 (0,0)까지 최단 시간 계산

import sys
from heapq import heappush, heappop
input = sys.stdin.readline

MAX_DIST = 10 ** 10
N, M, T, D = list(map(int, input().split()))
table = [[0 for _ in range(M)] for _ in range(N)]
# 출발 거리
st_dist = [[MAX_DIST for _ in range(M)] for _ in range(N)]
# 도착 거리
ed_dist = [[MAX_DIST for _ in range(M)] for _ in range(N)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for i in range(N):
    text = input().rstrip()
    for j in range(len(text)):
        table[i][j] = (ord(text[j]) - ord('A')) if ord(text[j]) < ord('a') else (ord(text[j]) - ord('a') + 26)

# 출발 거리 계산
queue = []
heappush(queue, (0, 0, 0))
st_dist[0][0] = 0
while len(queue) > 0:
    d, x, y = heappop(queue)
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx >= M or ny < 0 or ny >= N:
            continue
        if abs(table[y][x] - table[ny][nx]) > T:
            continue
        dist = d + 1 if table[y][x] >= table[ny][nx] else d + abs(table[y][x] - table[ny][nx]) ** 2
        if st_dist[ny][nx] > dist:
            st_dist[ny][nx] = dist
            heappush(queue, (dist, nx, ny))

# 도착 거리 계산
queue = []
heappush(queue, (0, 0, 0))
ed_dist[0][0] = 0
while len(queue) > 0:
    d, x, y = heappop(queue)
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx >= M or ny < 0 or ny >= N:
            continue
        if abs(table[y][x] - table[ny][nx]) > T:
            continue
        dist = d + 1 if table[y][x] <= table[ny][nx] else d + abs(table[y][x] - table[ny][nx]) ** 2
        if ed_dist[ny][nx] > dist:
            ed_dist[ny][nx] = dist
            heappush(queue, (dist, nx, ny))

ans = 0
for i in range(N):
    for j in range(M):
        if st_dist[i][j] + ed_dist[i][j] <= D:
            ans = max(ans, table[i][j])

print(ans)