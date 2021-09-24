import sys
input = sys.stdin.readline

arr = list(map(int, input().split()))
_sum = 0

for el in arr:
    _sum += el ** 2

print(_sum % 10)