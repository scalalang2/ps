import sys
input = sys.stdin.readline

n = int(input())
dp = [0 for _ in range(50001)]
dp[1] = 1
for i in range(1, n+1):
    dp[i] = dp[1] + dp[i-1]
    j = 2
    while j ** 2 <= i:
        dp[i] = min(dp[i], 1 + dp[i - j ** 2])
        j += 1

print(dp[n])