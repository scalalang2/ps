import sys
from collections import deque
input = sys.stdin.readline

LEFT = 1 << 0
TOP = 1 << 1
RIGHT = 1 << 2
BOTTOM = 1 << 3

n, m = [int(x) for x in input().split()]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
di = [LEFT, RIGHT, TOP, BOTTOM]
table = []
rooms = [[0 for _ in range(n)] for _ in range(m)]
room_cnt = 0
room_max_area = 0
max_sum_area = 0
rooms_area = {}

for _ in range(m):
    table.append([int(x) for x in input().split()])

def bfs(x, y):
    global room_cnt
    global rooms
    global room_max_area

    room_cnt += 1
    area = 1
    queue = deque([])
    queue.append((x, y))
    
    rooms[y][x] = room_cnt
    while len(queue) > 0:
        cx, cy = queue.popleft()
        for k in range(4):
            nx = cx + dx[k]
            ny = cy + dy[k]

            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue

            if di[k] & table[cy][cx] > 0:
                continue
            if rooms[ny][nx] != 0:
                continue

            rooms[ny][nx] = room_cnt
            queue.append((nx, ny))
            area += 1

    room_max_area = max(area, room_max_area)
    rooms_area[room_cnt] = area

for i in range(m):
    for j in range(n):
        if rooms[i][j] == 0:
            bfs(j, i)

for i in range(m):
    for j in range(n):
        if i-1 >= 0 and rooms[i-1][j] != rooms[i][j]:
            max_sum_area = max(max_sum_area, rooms_area[rooms[i-1][j]] + rooms_area[rooms[i][j]])
        if j-1 >= 0 and rooms[i][j-1] != rooms[i][j]:
            max_sum_area = max(max_sum_area, rooms_area[rooms[i][j-1]] + rooms_area[rooms[i][j]])

print(room_cnt)
print(room_max_area)
print(max_sum_area)
