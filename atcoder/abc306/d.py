import sys
input = sys.stdin.readline

GOOD_FOOD = 0
BAD_FOOD = 1

H = 0
U = 1

n = int(input())
food = []
dp = [[-1 for _ in range(2)] for _ in range(n+1)]
for i in range(n):
    X, Y = map(int, input().split())
    food.append((X, Y))
    
dp[0][H] = 0
dp[0][U] = 0

for j in range(1, n+1):
    typ = food[j-1][0]
    value = food[j-1][1]
        
    if typ == GOOD_FOOD:
        dp[j][H] = max(dp[j][H], dp[j-1][H])
        dp[j][H] = max(dp[j][H], dp[j-1][H] + value)
        dp[j][H] = max(dp[j][H], dp[j-1][U] + value)
        dp[j][U] = max(dp[j][U], dp[j-1][U])
    else:
        dp[j][H] = max(dp[j][H], dp[j-1][H])
        dp[j][U] = max(dp[j][U], dp[j-1][U])
        dp[j][U] = max(dp[j][U], dp[j-1][H] + value)


print(max(dp[n][H], dp[n][U]))