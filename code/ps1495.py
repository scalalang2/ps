import sys
input = sys.stdin.readline

N, S, M = list(map(int, input().split()))
arr = list(map(int, input().split()))
dp = [[False for _ in range(M+1)] for _ in range(N+1)]
# dp[N][S] = N 번째 리스트에서 S 볼륨이 가능한지 아닌지
dp[0][S] = True

for i in range(1, N+1):
    for j in range(M+1):
        if dp[i-1][j] and j - arr[i-1] >= 0:
            dp[i][j - arr[i-1]] = True

        if dp[i-1][j] and j + arr[i-1] <= M:
            dp[i][j + arr[i-1]] = True

ans = -1
for i in range(M, -1, -1):
    if dp[N][i]:
        ans = i
        break

print(ans)