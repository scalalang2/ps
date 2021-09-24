import sys
from collections import deque
input = sys.stdin.readline

n, t, g = list(map(int, input().split()))
MAX = t + 1

dist = [MAX for _ in range(100000)]
queue = deque([n])
dist[n] = 0

while len(queue) > 0:
    num = queue.popleft()

    if num + 1 <= 99999 and dist[num] + 1 < dist[num + 1]:
        dist[num + 1] = dist[num] + 1
        queue.append(num + 1)
        
    if num * 2 <= 99999:
        txt = list(str(num * 2))
        for i in range(len(txt)):
            if txt[i] != '0':
                txt[i] = str(int(txt[i]) - 1)
                break
        new_num = int(''.join(txt))
        if dist[num] + 1 < dist[new_num]:
            dist[new_num] = dist[num] + 1
            queue.append(new_num)

if dist[g] == MAX:
    print("ANG")
else:
    print(dist[g])