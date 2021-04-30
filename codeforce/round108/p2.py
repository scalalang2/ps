import sys
from collections import deque
input = sys.stdin.readline

T = int(input())
dx = [1, 0]
dy = [0, 1]

for _ in range(T):
    n, m, k = list(map(int, input().split()))
    ans = False
    queue = deque([])
    queue.append((1, 1, 0))
    visited = [[False for _ in range(m+1)] for _ in range(n+1)]
    while len(queue) > 0:
        y, x, cnt = queue.popleft()
        if y == n and x == m and cnt == k:
            ans = True
            break

        for i in range(2):
            nx = x + dx[i]
            ny = y + dy[i]
            if ny > n or nx > m or visited[ny][nx]:
                continue

            visited[ny][nx] = True

            if i == 0:
                if not (cnt + y > k):
                    queue.append((ny, nx, cnt + y))
            else:
                if not (cnt + x > k):
                    queue.append((ny, nx, cnt + x))
    if ans:
        print("YES")
    else:
        print("NO")