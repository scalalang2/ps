import sys
input = sys.stdin.readline
N = int(input())

# 아니 실화냐
# 문제를 잘못이해해서 한 시간 동안 다르게 풀고 있었네 ㅡㅡ
# 문제좀 제대로 읽고 풀자 후..
# 그냥 단순 그리디 계산이잖어 ㅡㅡ

ans = 0
up = 1
down = 1
M = 998244353

A = []
B = []

for i in range(N):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)

for i in range(1, N):
    new_up = 0
    new_down = 0
    if A[i] != A[i-1] and A[i] != B[i-1]:
        new_up = up + down
        new_up %= M
    if A[i] == A[i-1] and A[i] != B[i-1]:
        new_up = down
    if A[i] == B[i-1] and A[i] != A[i-1]:
        new_up = up
    if B[i] != A[i-1] and B[i] != B[i-1]:
        new_down = up + down
        new_down %= M
    if B[i] == A[i-1] and B[i] != B[i-1]:
        new_down = down
    if B[i] == B[i-1] and B[i] != A[i-1]:
        new_down = up

    up = new_up
    down = new_down

print((up + down)%M)