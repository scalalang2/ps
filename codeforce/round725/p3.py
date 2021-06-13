import sys
from bisect import bisect_left
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, l, r = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    arr.sort()
    # print(arr)
    
    ans = 0
    for i in range(n):
        lower = bisect_left(arr, l - arr[i])
        upper = bisect_left(arr, r - arr[i])
        if i < lower:
            ans += upper - lower
        elif i < upper:
            if upper == n:
                ans += upper - i - 1
            else:
                ans += upper - i

    print(ans)

# 4
# 3 4 7
# 5 1 2
# 5 5 8
# 5 1 2 4 3
# 4 100 1000
# 1 1 1 1
# 5 9 13
# 2 5 5 1 1