# 3
# 1 2 3
# 4 5 6
# 4 9 0

import sys
input = sys.stdin.readline

N = int(input())
arr = []
for i in range(N):
    arr.append(list(map(int, input().split())))

min_val = [[0 for _ in range(3)] for _ in range(2)]
max_val = [[0 for _ in range(3)] for _ in range(2)]
min_val[0] = arr[0].copy()
max_val[0] = arr[0].copy()

for i in range(1, N):
    min_val[1] = arr[i].copy()
    max_val[1] = arr[i].copy()

    min_val[1][0] += min(min_val[0][0], min_val[0][1])
    min_val[1][1] += min(min_val[0][0], min_val[0][1], min_val[0][2])
    min_val[1][2] += min(min_val[0][1], min_val[0][2])
    
    max_val[1][0] += max(max_val[0][0], max_val[0][1])
    max_val[1][1] += max(max_val[0][0], max_val[0][1], max_val[0][2])
    max_val[1][2] += max(max_val[0][1], max_val[0][2])

    min_val[0] = min_val[1].copy()
    max_val[0] = max_val[1].copy()

print(max(max_val[0]), min(min_val[0]))