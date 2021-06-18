import sys
from bisect import bisect_left, bisect_right
input = sys.stdin.readline

ans = []

t = int(input())
for _ in range(t):
    n, l, r = list(map(int, input().split()))
    v = list(map(int, input().split()))
    v.sort()
    
    ret = 0
    for i in range(n):
        lower = bisect_left(v, l - v[i]) + 1
        upper = bisect_right(v, r - v[i]) + 1
        if l <= 2 * v[i] <= r:
            ret -= 1
        ret += upper - lower
    ans.append(ret // 2)

for el in ans:
    print(el)