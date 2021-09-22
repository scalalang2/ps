import sys
input = sys.stdin.readline

n = int(input())
arr = [int(x) for x in input().split()]
dp = [False for x in range(400001)]
ans = 0

def map_to_idx(num):
    return num + 200000

for i in range(n):
    for j in range(i):
        if dp[map_to_idx(arr[i] - arr[j])]:
            ans += 1
            break

    for j in range(i+1):
        dp[map_to_idx(arr[i] + arr[j])] = True

print(ans)