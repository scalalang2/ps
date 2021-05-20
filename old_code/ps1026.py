# 5
# 1 1 1 6 0
# 2 7 8 3 1
import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort()
B.sort(reverse=True)
ans = 0
for i in range(len(A)):
    ans += A[i] * B[i]

print(ans)