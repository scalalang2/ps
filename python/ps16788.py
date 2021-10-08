import sys
from heapq import heappush, heappop

input = sys.stdin.readline 

# 6
# 0 1 2 1 3 2
n = int(input())
new_n = 0
arr = [int(x) for x in input().split()]

if sum(arr) == 0:
    print(0)
    exit(0)

A = [-1]
for i in range(n):
    if i > 0 and arr[i-1] == arr[i]:
        continue
    A.append(arr[i])
    new_n += 1
A.append(-1)

n = new_n

heap = []

for i in range(n):
    heappush(heap, (A[i+1], i+1))

ans = 1
cnt = 0

while len(heap) > 0:
    x, idx = heappop(heap)    

    if A[idx+1] > x and A[idx-1] > x:
        if cnt == 0:
            cnt += 2
        else:
            cnt += 1
    elif A[idx+1] < x and A[idx-1] < x:
        cnt -= 1
    
    if len(heap) > 0 and heap[0][0] > x:
        ans = max(ans, cnt)
    elif len(heap) == 0:
        ans = max(ans, cnt)

print(ans)