import sys
from collections import deque
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    power = [0 for _ in range(101)]
    stones = list(map(int, input().split()))

    for i in range(len(stones)):
        power[stones[i]] = i + 1
    
    minIndex = power[min(stones)]
    maxIndex = power[max(stones)]
    ans = 101
    
    if minIndex < maxIndex:
        ans = min(ans, maxIndex, len(stones) - minIndex + 1, minIndex + len(stones) - maxIndex + 1)
    else:
        ans = min(ans, minIndex, len(stones) - maxIndex + 1, maxIndex + len(stones) - minIndex + 1)

    print(ans)

