import sys
from heapq import heappush, heappop
input = sys.stdin.readline

n = int(input())
task = []
for _ in range(n):
    time, cost = [int(x) for x in input().split()]
    task.append((time, cost))

task.sort()
heap = []

for time, cost in task:
    heappush(heap, cost)
    if len(heap) > time:
        heappop(heap)

print(sum(heap))