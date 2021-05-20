import sys
from collections import deque
input = sys.stdin.readline

N,M,K = list(map(int, input().split()))
queue = deque([])
queue.append((1, 1))

dp = [[0 for _ in range(M)] for _ in range(N)]
dp[0][0] = 0
dx = [0, 1]
dy = [1, 0]

while len(queue) > 0:
    x, y = queue.popleft()
    kx = M if K % M == 0 else K % M
    ky = K // M + 1

    for i in range(2):
        nx = x + dx[i]
        ny = y + dy[i]

        if ny > N or nx > M:
            continue

        if x == kx and y == ky:
            dp[ny-1][nx-1] += 1
        else:
            dp[ny-1][nx-1] += dp[y-1][x-1]

        queue.append((nx, ny))

print(dp[N-1][M-1])
print(dp)