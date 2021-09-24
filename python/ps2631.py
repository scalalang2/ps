# 증가하는 수열을 찾는다면 그 요소를 제외한 나머지 애들이 순서를 바꿔야 하는 친구들이다.
import sys
input = sys.stdin.readline

n = int(input())
arr = []
dp = [0 for _ in range(n)]
ans = 0

for _ in range(n):
    arr.append(int(input()))

for i in range(n):
    dp[i] = 1
    for j in range(i):
        if arr[i] > arr[j] and dp[i] < dp[j] + 1:
            dp[i] = dp[j] + 1

print(n - max(dp))