from collections import deque
import sys
input = sys.stdin.readline

# 15
# push 1
# push 2
# front
# back
# size
# empty
# pop
# pop
# pop
# size
# empty
# pop
# push 3
# empty
# front
queue = deque([])
N = int(input())
for _ in range(N):
    arr = input().split()
    if len(arr) > 1:
        queue.append(int(arr[1]))
    else:
        if arr[0] == 'front':
            if len(queue) > 0:
                print(queue[0])
            else:
                print(-1)
        elif arr[0] == 'back':
            if len(queue) > 0:
                print(queue[len(queue) - 1])
            else:
                print(-1)
        elif arr[0] == 'size':
            print(len(queue))
        elif arr[0] == 'pop':
            if len(queue) > 0:
                print(queue.popleft())
            else:
                print(-1)
        elif arr[0] == 'empty':
            if len(queue) == 0:
                print(1)
            else:
                print(0)
