import sys
input = sys.stdin.readline

N = int(input())
dp = [[0 for _ in range(3)] for _ in range(1516)]

dp[0][0] = 0 # 나머지가 0인 경우의 수
dp[0][1] = 0 # 1XX / 나머지가 5인 경우의 수가 필요함, 나머지가 10인 경우
dp[0][2] = 1 # 5XX / 나머지가 10인 경우의 수가 필요함, 나머지가 5인 경우
dp[1][0] = 1
dp[1][1] = 1
dp[1][2] = 0

for i in range(2, N):
    dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % 1000000007
    dp[i][1] = (dp[i-1][2] + dp[i-1][0]) % 1000000007
    dp[i][2] = (dp[i-1][1] + dp[i-1][0]) % 1000000007

print(dp[N-1][0])