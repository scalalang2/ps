import sys
input = sys.stdin.readline

n, m = list(map(int, input().split()))
arr = list(map(int, input().split()))
psum = [0 for _ in range(n)]
psum[0] = arr[0]

for i in range(1, n):
    psum[i] = psum[i-1] + arr[i]

for _ in range(m):
    i, j = list(map(int, input().split()))
    if i == j:
        print(arr[i-1])
    else:
        print(psum[j-1] - psum[i-1] + arr[i-1])