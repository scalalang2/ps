from collections import deque
import sys
input = sys.stdin.readline


T = int(input())
while T:
    lstack = []
    rstack = []

    text = input().rstrip()
    for i in range(len(text)):
        if text[i] == '<':
            if len(lstack) > 0:
                rstack.append(lstack.pop())
        elif text[i] == '>':
            if len(rstack) > 0:
                lstack.append(rstack.pop())
        elif text[i] == '-':
            if len(lstack) > 0:
                lstack.pop()
        else:
            lstack.append(text[i])

    while len(rstack) > 0:
        lstack.append(rstack.pop())
    print(''.join(lstack))

    T -= 1