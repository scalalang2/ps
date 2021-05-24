import sys
input = sys.stdin.readline

N, M = list(map(int, input().split()))
arr = list(map(int, input().split()))
cnt = [0 for _ in range(M)]

for i in range(1, N):
    arr[i] += arr[i-1]

for i in range(N):
    cnt[arr[i] % M] += 1

ans = cnt[0]
for i in range(M):
    ans += cnt[i] * (cnt[i]-1) // 2

print(ans)