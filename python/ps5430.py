import sys
from collections import deque
input = sys.stdin.readline

T = int(input())

while T:
    T -= 1
    ops = input().rstrip()
    n = int(input())
    text = input().rstrip()
    text = text[1:len(text)-1].split(',')
    queue = deque([])

    flip = False
    has_error = False
    for el in text:
        if el == '':
            continue
        queue.append(el)
    
    for el in ops:
        if el == 'R':
            flip = not flip
        if el == 'D':
            if flip:
                if len(queue) > 0:
                    queue.pop()
                else:
                    has_error = True
            else:
                if len(queue) > 0:
                    queue.popleft()
                else:
                    has_error = True
    
    if has_error:
        print('error')
        continue

    if flip:
        queue.reverse()
        print('[' + ','.join(queue) + ']')
    else:
        print('[' + ','.join(queue) + ']')