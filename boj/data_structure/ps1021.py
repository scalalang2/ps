from collections import deque
import sys
input = sys.stdin.readline

N, M = list(map(int, input().split()))
nums = list(map(int, input().split()))

queue = deque([])
for i in range(N):
    queue.append(i+1)

def find_num(n):
    for i in range(len(queue)):
        if queue[i] == n:
            return i
    return -1

i = 0
ans = 0
while i < M:
    idx = find_num(nums[i])
    if len(queue) - idx > idx:
        while idx > 0:
            queue.append(queue.popleft())
            idx -= 1
            ans += 1
    else:
        while idx < len(queue):
            queue.appendleft(queue.pop())
            idx += 1
            ans += 1
    queue.popleft()
    i+=1

print(ans)
