import sys 
from collections import deque
input = sys.stdin.readline

n, d, k, c = list(map(int, input().split()))

arr = []
for _ in range(n):
    arr.append(int(input()))

tbl = deque([])
chk = [0 for _ in range(d+1)]
ans = 0

ret = 0
for i in range(k):
    if chk[arr[i]] == 0:
        ret += 1
    tbl.append(arr[i])
    chk[arr[i]] += 1

if chk[c] == 0:
    ans = ret + 1
else:
    ans = ret

for i in range(1, n):
    idx = (i + k - 1) % n

    remove = tbl.popleft()
    chk[remove] -= 1
    if chk[remove] == 0:
        ret -= 1
    
    if chk[arr[idx]] == 0:
        ret += 1

    chk[arr[idx]] += 1
    tbl.append(arr[idx])
    # print(tbl, i, c, chk[c], ret)
    if chk[c] == 0:
        ans = max(ret + 1, ans)
    else:
        ans = max(ret, ans)

print(ans)
    
