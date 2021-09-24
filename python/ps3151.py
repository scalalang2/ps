import sys
from collections import defaultdict

input = sys.stdin.readline

n = int(input())
arr = [int(x) for x in input().split()]
arr.sort()
cnt = 0

def hash(left, mid, right):
    return str(left) + ":" + str(mid) + ":" + str(right)

def twopointer(left, mid, right):
    global cnt

    while left < mid and mid < right:
        _sum = arr[left] + arr[mid] + arr[right]
        if _sum == 0:
            cnt += 1
            left += 1
            temp = right - 1
            while left < mid and mid < temp:
                _sum = arr[left - 1] + arr[mid] + arr[temp]
                if _sum == 0:
                    cnt += 1
                elif _sum < 0:
                        break
                temp -= 1
        elif _sum < 0:
            left += 1
        else:
            right -= 1

for mid in range(1, n-1):
    twopointer(0, mid, n - 1)

print(cnt)