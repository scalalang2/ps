import sys
from bisect import bisect_left
input = sys.stdin.readline

n = int(input())
arr = [int(x) for x in input().split()]
m = int(input())
queries = [int(x) for x in input().split()]
arr.sort()

for q in queries:
    found = False
    l = 0
    r = n-1
    while l <= r:
        mid = (l + r) // 2
        if arr[mid] < q:
            l = mid + 1
        elif arr[mid] > q:
            r = mid - 1
        else:
            found = True
            break

    if found:
        print(1)
    else:
        print(0)