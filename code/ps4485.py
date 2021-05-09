from collections import deque
import sys
input = sys.stdin.readline

MAX = 125 * 125 * 9 + 10 ** 5

while True:
    n = int(input())
    if n == 0:
        break

    board = []
    for _ in range(n):
        board.append(list(map(int, input().split())))
    
    # 각 칸마다 얻을 수 있는 최소비용
    costs = [[MAX for i in range(n)] for j in range(n)]

    # 방문 여부
    visited = [[False for i in range(n)] for j in range(n)]

    dx = [1, 0]
    dy = [0, 1]

    costs[0][0] = board[0][0]
    queue = deque([])
    queue.append((0, 0))

    while len(queue) > 0:
        x, y = queue.popleft()
        for i in range(2):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx >= n or ny >= n:
                continue

            cost[ny][nx] = min(cost[ny][nx], cost[y][x] + board[ny][nx])