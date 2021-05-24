import sys
input = sys.stdin.readline

n = int(input())
MAX = 100
dp = [0 for _ in range(MAX + 1)]
dp[1] = 0
dp[2] = 1

for i in range(3, MAX + 1):
    dp[i] = dp[i-1] + dp[i-2]
print(dp[n+1])
