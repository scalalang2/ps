import sys
from heapq import heappop, heappush
input = sys.stdin.readline

n = int(input())
classes = []
inclass = []

ans = 0

for _ in range(n):
    s, e = list(map(int, input().split()))
    heappush(classes, (s, e))

while len(classes) > 0:
    s, e = heappop(classes)

    while len(inclass) > 0:
        if s >= inclass[0]:
            heappop(inclass)
        else:
            break
    
    # print(ans, len(inclass))
    heappush(inclass, e)
    ans = max(ans, len(inclass))

print(ans)
