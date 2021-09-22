import sys
input = sys.stdin.readline

n = int(input())
a = []
b = []
for _ in range(n):
    x, y = [int(x) for x in input().split()]
    a.append(x + y)
    b.append(x - y)

a.sort()
b.sort()

print(max(a[-1] - a[0], b[-1] - b[0]))