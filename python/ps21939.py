import sys
from collections import defaultdict
from heapq import heappush, heappop

n = int(input())
maxheap = []
minheap = []
ans = []
solved = [0 for _ in range(100001)]
difficulty = defaultdict(int)

for _ in range(n):
    num, score = list(map(int, input().split()))
    heappush(maxheap, (score * -1, num * -1))
    heappush(minheap, (score, num))
    difficulty[num] = score

t = int(input())
for _ in range(t):
    command = input().split()
    if command[0] == 'add':
        num = int(command[1])
        score = int(command[2])
        solved[num] = 0
        difficulty[num] = score
        heappush(maxheap, (score * -1, num * -1))
        heappush(minheap, (score, num))
    elif command[0] == 'recommend':
        if int(command[1]) == -1:
            while len(minheap) > 0:
                score, num = heappop(minheap)
                if solved[num] == 0 and score == difficulty[num]:
                    ans.append(num)
                    heappush(minheap, (score, num))
                    break
        else:
            while len(maxheap) > 0:
                score, num = heappop(maxheap)
                if solved[num*-1] == 0 and score * -1 == difficulty[num*-1]:
                    ans.append(num * -1)
                    heappush(maxheap, (score, num))
                    break
    elif command[0] == 'solved':
        solved[int(command[1])] = 1

for el in ans:
    print(el)