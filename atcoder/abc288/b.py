import sys
input = sys.stdin.readline

n, k = map(int, input().split())
arr = []

for i in range(n):
    arr.append(input().rstrip())

ans = arr[:k]
ans.sort()
for el in ans:
    print(el)