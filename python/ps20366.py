# 투 포인터를 두 개 사용하면 되나?
import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
arr.sort()

ans = 10 ** 9

l = 0
r = n-1
turn = False

for l in range(n-1):
    for r in range(l+1, n):
        nl = l + 1
        nr = r - 1
        if nl == l or nl == r:
            nl += 1
            continue
        if nr == l or nr == r:
            nr -= 1
            continue

        while nl < nr:
            ret = abs((arr[l] + arr[r]) - (arr[nl] + arr[nr]))
            ans = min(ans, ret)
            if arr[nl] + arr[nr] < arr[l] + arr[r]:
                nl += 1
            else:
                nr -= 1

print(ans)