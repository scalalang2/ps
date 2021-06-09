import sys
from collections import deque
input = sys.stdin.readline

MAX = 10 ** 10
start_num   = input().rstrip()
target_num  = input().rstrip()
dist = [MAX for _ in range((1 << 13) - 1)]

def to_num(bin):
    size = len(bin) - 1
    length = len(bin) - 1
    num = 0
    while size >= 0:
        if bin[size] == '1':
            num += 1 << (length - size)
        size -= 1
    return num

t_num = to_num(target_num)
dist[to_num(start_num)] = 0
queue = deque([])
queue.append(to_num(start_num))

while len(queue) > 0:
    num = queue.popleft()

    if num - 1 >= 0 and dist[num - 1] > dist[num] + 1:
        dist[num - 1] = dist[num] + 1
        queue.append(num - 1)
    
    if num + 1 < (1 << 12) - 1 and dist[num+1] > dist[num] + 1:
        dist[num+1] = dist[num] + 1
        queue.append(num + 1)
    
    if num > 0 and num < (1 << 12) - 1:
        st = 12
        while True:
            if (1 << st & num) == 0:
                st -= 1
            else:
                st -= 1
                break
        while st >= 0:
            if dist[num ^ (1 << st)] > dist[num] + 1:
                dist[num ^ (1 << st)] = dist[num] + 1
                queue.append(num ^ (1 << st))
            st -= 1
            
print(dist[t_num])