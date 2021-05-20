import sys
from heapq import heappush, heappop

input = sys.stdin.readline

N = int(input())
K = int(input())
sensors = list(map(int, input().split()))
sensors.sort()

adj = []
for i in range(1, len(sensors)):
    adj.append(sensors[i] - sensors[i-1])

adj.sort()
answer = 0
for i in range(len(adj) - K + 1):
    answer += adj[i]

# print(sensors)
# print(adj)
print(answer)