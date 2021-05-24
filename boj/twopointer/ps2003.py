import sys
input = sys.stdin.readline

N, M = list(map(int, input().split()))
arr = list(map(int, input().split()))

L, R = 0, 0
S = 0
ans = 0
while True:
    if S >= M:
        S -= arr[L]
        L += 1
    elif R == N:
        break
    else:
        S += arr[R]
        R += 1

    if S == M:
        ans += 1

print(ans)