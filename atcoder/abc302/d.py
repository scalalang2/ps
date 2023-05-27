import sys
from bisect import bisect_left, bisect_right
n, m, d = map(int, sys.stdin.readline().split())
cands_for_A = list(map(int, sys.stdin.readline().split()))
cands_for_B = list(map(int, sys.stdin.readline().split()))

cands_for_A.sort()
cands_for_B.sort()

ans = -1

for i in range(n):
    A = cands_for_A[i]
    it = bisect_left(cands_for_B, A + d)
    if it == m:
        it -= 1
    B = cands_for_B[it]
    if abs(A - B) <= d:
        ans = max(ans, A + B)

    if it + 1 < m:
        B = cands_for_B[it + 1]
        if abs(A - B) <= d:
            ans = max(ans, A + B)

for i in range(n):
    A = cands_for_A[i]
    it = bisect_right(cands_for_B, A - d)
    if it == m:
        it -= 1
    B = cands_for_B[it]
    if abs(A - B) <= d:
        ans = max(ans, A + B)

    if it + 1 < m:
        B = cands_for_B[it + 1]
        if abs(A - B) <= d:
            ans = max(ans, A + B)

for i in range(m):
    A = cands_for_B[i]
    it = bisect_left(cands_for_A, A + d)
    if it == n:
        it -= 1
    B = cands_for_A[it]
    if abs(A - B) <= d:
        ans = max(ans, A + B)

    if it + 1 < n:
        B = cands_for_A[it + 1]
        if abs(A - B) <= d:
            ans = max(ans, A + B)

for i in range(m):
    A = cands_for_B[i]
    it = bisect_right(cands_for_A, A - d)
    if it == n:
        it -= 1
    B = cands_for_A[it]
    if abs(A - B) <= d:
        ans = max(ans, A + B)

    if it + 1 < n:
        B = cands_for_A[it + 1]
        if abs(A - B) <= d:
            ans = max(ans, A + B)

print(ans)