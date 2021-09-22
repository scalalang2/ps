import sys
from collections import deque
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# X, Y 에서 출발해서 임의의 지점으로 갈 수 있는 방법에서 문을 딴 회수가 가장 적은 경우
def bfs(x, y):
    queue = deque([])
    queue.append((x, y))
    dist = [[-1 for _ in range(w + 2)] for _ in range(h + 2)]
    dist[y][x] = 0

    while len(queue) > 0:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if nx < 0 or nx >= w + 2 or ny < 0 or ny >= h + 2:
                continue
            
            if world[ny][nx] == '*':
                continue

            if dist[ny][nx] != -1:
                continue
            
            if world[ny][nx] == '#':
                dist[ny][nx] = dist[y][x] + 1
                queue.append((nx, ny))
            else:
                dist[ny][nx] = dist[y][x]
                queue.appendleft((nx, ny))

    return dist

t = int(input())
for _ in range(t):
    h, w = [int(x) for x in input().split()]
    world = []
    world.append(['.' for _ in range(w + 2)])

    # 탈옥수
    px = []
    py = []

    for i in range(h):
        tile = ['.']
        txt = input().rstrip()
        for j in range(w):
            if txt[j] == '$':
                px.append(j+1)
                py.append(i+1)
                tile.append('.')
            else:
                tile.append(txt[j])
        tile.append('.')
        world.append(tile)

    world.append(['.' for _ in range(w + 2)])

    # 탈옥수 P0 에서 출발
    dist1 = bfs(px[0], py[0])
    
    # 탈옥수 P1 에서 출발
    dist2= bfs(px[1], py[1])

    # 탈옥수 0,0 에서 출발
    dist3 = bfs(0, 0)

    ans = sys.maxsize

    for i in range(h+2):
        for j in range(w+2):
            if world[i][j] == '*':
                continue

            if dist1[i][j] == -1 or dist2[i][j] == -1 or dist3[i][j] == -1:
                continue
            
            ret = dist1[i][j] + dist2[i][j] + dist3[i][j]
            if world[i][j] == '#':
                ret -= 2
            ans = min(ans,ret)
    
    print(ans)