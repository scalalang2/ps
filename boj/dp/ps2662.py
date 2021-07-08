import sys
input = sys.stdin.readline

# N = 투자금
# M = 회사 수
N, M    = [int(x) for x in input().split()]

cost    = [[0 for _ in range(N+1)] for _ in range(M+1)]
dp      = [[0 for _ in range(N+1)] for _ in range(M+1)]
trace   = [[0 for _ in range(N+1)] for _ in range(M+1)]

for money in range(1, N + 1):
    arr = [int(x) for x in input().split()]
    for com in range(1, M+1):
        cost[com][money] = arr[com]

ans = 0
mx = 0
for i in range(1, M+1):
    for c in range(1, N+1):
        for prev in range(c+1):
            new = cost[i][c-prev] + dp[i - 1][prev]
            if new > dp[i][c]:
                dp[i][c] = new
                trace[i][c] = prev
            
        ans = max(ans, dp[i][c])            
        if dp[i][c] == ans:
            mx = c

print(ans)
ret = []
for i in range(M, 0, -1):
    ret.append(mx-trace[i][mx])
    mx = trace[i][mx]

ret.reverse()
print(' '.join(list(map(str, ret))))