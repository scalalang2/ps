import sys
input = sys.stdin.readline

N = 1000
arr = [False for _ in range(N+1)]

for i in range(2, N + 1):
    temp = i
    if arr[i]:
        continue
    while temp + i < N + 1:
        temp += i
        arr[temp] = True
arr[1] = True

m = int(input())
arr2 = list(map(int, input().split()))
cnt = 0

for el in arr2:
    if not arr[el]:
        cnt += 1

print(cnt)