import sys
from heapq import heappush, heappop
input = sys.stdin.readline

N, M = map(int, input().split())
S = [[] for _ in range(M)]
for i in range(M):
    C = input()
    S[i] = list(map(int, input().split()))

Q = []
for i in range(M):
    heappush(Q, (S[i][-1], i))


cnt = 0
last = 0
while len(Q) > 0:
    cur, pos = heappop(Q)
    if last+1 != cur:
        print("No")
        exit()
    last = cur
    cnt += 1
    S[pos].pop()
    if len(S[pos]) > 0:
        heappush(Q, (S[pos][-1], pos))

if cnt == N:
    print("Yes")
else:
    print("No")