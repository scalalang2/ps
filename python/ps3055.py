import sys
from collections import deque
input = sys.stdin.readline

WATER = 2501
WALLS = 2502

r, c = list(map(int, input().split()))
table = [[-1 for _ in range(c)] for _ in range(r)]
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

# 고슴도치
sx, sy = 0, 0

# 굴 위치
ex, ey = 0, 0

# 초기화
queue = deque([])
for i in range(r):
    txt = input().rstrip()
    for j in range(len(txt)):
        if txt[j] == 'X':
            table[i][j] = WALLS
        elif txt[j] == '*':
            table[i][j] = WATER
            queue.append((j, i, WATER))
        elif txt[j] == 'D':
            ex = j
            ey = i
        elif txt[j] == 'S':
            sx = j
            sy = i

queue.append((sx, sy, 0))
table[sy][sx] = 0

while len(queue) > 0:
    x, y, dist = queue.popleft()

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if ny < 0 or ny >= r or nx < 0 or nx >= c:
            continue
        if table[ny][nx] == WALLS:
            continue
        if table[ny][nx] == WATER:
            continue
        if dist == WATER:
            if ny == ey and nx == ex:
                continue
            table[ny][nx] = WATER
            queue.append((nx, ny, WATER))
        else:
            if table[ny][nx] == -1:
                table[ny][nx] = dist + 1
                queue.append((nx, ny, dist + 1))

if table[ey][ex] == -1:
    print("KAKTUS")
else:
    print(table[ey][ex])