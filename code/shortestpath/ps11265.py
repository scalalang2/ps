import sys
input = sys.stdin.readline

N, Q = list(map(int, input().split()))
arr = []
for i in range(N):
    arr.append(list(map(int, input().split())))

for k in range(N):
    for i in range(N):
        for j in range(N):
            arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j])

for _ in range(Q):
    u, v, s = list(map(int, input().split()))

    if arr[u-1][v-1] >= s:
        print("Stay here")
    else:
        print("Enjoy other party")
