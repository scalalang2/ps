import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

stack = []
queue = deque([])

i = 0
while i < n:
    t = 1 if len(queue) == 0 else queue[len(queue)-1] + 1
    if arr[i] == t:
        queue.append(arr[i])
        i += 1
    elif len(stack) > 0 and t == stack[len(stack)-1]:
        queue.append(stack.pop())
    else:
        stack.append(arr[i])
        i += 1

flag = True
while len(stack) > 0:
    el = stack.pop()
    t = 1 if len(queue) == 0 else queue[len(queue)-1] + 1
    if t == el:
        queue.append(el)
    else:
        flag = False

if flag:
    print("Nice")
else:
    print("Sad")