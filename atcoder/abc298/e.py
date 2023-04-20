from pprint import pprint
import sys
input = sys.stdin.readline
N, A, B, P, Q = map(int, input().split())
mod = 998244353
 
dp = [[[0 for _ in range(2)] for _ in range(N + 1)] for _ in range(N + 1)]
 
pinv = pow(P, mod - 2, mod)
qinv = pow(Q, mod - 2, mod)

for i in range(0, N):
  for f in range(2):
    dp[N][i][f] = 1
    dp[i][N][f] = 0

for i in range(N-1, -1, -1):
    for j in range(N-1, -1, -1):
        for k in range(1, P+1):
            # (i,j) 에서 이길 확률은
            # (i+k,j)의 위치에서 Aoki가 선턴을 잡았는데도 이기는 확률을 더함
            dp[i][j][0] += dp[min(i+k, N)][j][1] * pinv
            dp[i][j][0] %= mod
        for k in range(1, Q+1):
            # (i,j) 에서 이길 확률은
            # Aoki가 (i,j+k) 로 이동하고 다음 턴에서 내가 잡았을 때의 이기는 확률을 더한다.
            dp[i][j][1] += dp[i][min(j+k, N)][0] * qinv
            dp[i][j][1] %= mod
 
print(dp[A][B][0])