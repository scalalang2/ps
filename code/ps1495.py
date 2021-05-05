import sys
input = sys.stdin.readline

N, S, M = list(map(int, input().split()))
arr = list(map(int, input().split()))
ans = 0

def f(i, v):
    global ans

    if i == N:
        ans = max(ans, v)
        return

    if v + arr[i] <= M:
        f(i+1, v + arr[i])

    if v - arr[i] >= 0:
        f(i+1, v - arr[i])

f(0, S)
print(ans)

# f(i) = max(f(i-1, on)의 최대값, f(i-1, off)의 최대값) + V or - V