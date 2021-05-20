from collections import deque
import sys
input = sys.stdin.readline

queue = deque([])

N = int(input())
ops = list(map(int, input().split()))

nums = 1
for i in range(len(ops) -1, -1, -1):
    if ops[i] == 1:
        queue.appendleft(nums)
    elif ops[i] == 2:
        if len(queue) > 0:
            el = queue.popleft()
            queue.appendleft(nums)
            queue.appendleft(el)
        else:
            queue.appendleft(nums)
    else:
        queue.append(nums)
    nums += 1

print(' '.join(list(map(str, queue))))