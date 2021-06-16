import sys
from collections import deque
input = sys.stdin.readline

left = deque([])
right = deque([])
arr = []
# 0 이면 left
# 1 이면 right
ship = 0
clock = 0

M, T, N = list(map(int, input().split()))
ans = [0 for _ in range(N)]

for i in range(N):
    time, direction = input().split()
    arr.append((int(time), direction, i))
arr.sort()

for i in range(N):
    time, direction, index = arr[i]
    if direction == 'left':
        left.append((time, index))
    else:
        right.append((time, index))

while len(left) > 0 or len(right) > 0:
    cnt = 0

    if ship == 0:
        while len(left) > 0 and left[0][0] <= clock and cnt < M:
            time, index = left.popleft()
            ans[index] = clock + T
            cnt += 1
        if cnt > 0:
            ship = 1
            clock += T
    else:
        while len(right) > 0 and right[0][0] <= clock and cnt < M:
            time, index = right.popleft()
            ans[index] = clock + T
            cnt += 1
        if cnt > 0:
            ship = 0
            clock += T
    
    if cnt == 0:
        if ship == 0 and len(right) > 0 and right[0][0] <= clock:
            clock += T
            ship = 1
        elif ship == 1 and len(left) > 0 and left[0][0] <= clock:
            clock += T
            ship = 0
        else:
            clock += 1

for el in ans:
    print(el)