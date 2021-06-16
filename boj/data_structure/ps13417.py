import sys
from collections import deque
input = sys.stdin.readline

t = int(input())

while t > 0:
    n = int(input())
    cards = input().split()
    text = deque([])
    
    for i in range(n):
        if len(text) == 0:
            text.append(cards[i])
            continue
        if cards[i] <= text[0]:
            text.appendleft(cards[i])
        else:
            text.append(cards[i])
    
    print(''.join(text))
    t -= 1