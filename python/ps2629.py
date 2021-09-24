import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
w = list(map(int, input().split())) # 추의 무게들
t = int(input())
arr = list(map(int, input().split())) # 알아야 할 추 무게들

dp = [[False for _ in range(40001)] for _ in range(31)]
dp[0][0] = True
dp[0][w[0]] = True

for i in range(1, n):
    for j in range(40001):
        if dp[i-1][j]:
            dp[i][j] = True
            dp[i][j + w[i]] = True
            if abs(j - w[i]) >= 0:
                dp[i][abs(j - w[i])] = True

text = ""
for i in range(t):
    if dp[n-1][arr[i]]:
        text += "Y "
    else:
        text += "N "

print(text)