import sys
from functools import cmp_to_key
from heapq import heappush, heappop
input = sys.stdin.readline

def f(a, b, t):
    return a * t + b

def comp(item1, item2):
    a1, b1 = item1
    a2, b2 = item2

    if a1 == 0:
        return 1
    elif a2 == 0:
        return -1
    elif b1 == 0 and b2 == 0:
        if a1 < a2:
            return -1
        else:
            return 1
    else:
        if b1 * a2 < b2 * a1:
            return -1
        else:
            return 1

    # c = f(a1, b1, 5) + f(a2, b2, f(a1, b1, 5))
    # d = f(a2, b2, 5) + f(a1, b1, f(a2, b2, 5))

    # # A의 시간이 더 짧게 걸린다면
    # if c < d:
    #     return 1
    # else:
    #     return -1

n = int(input())
lines = []
for _ in range(n):
    a, b = list(map(int, input().split()))
    lines.append((a,b))

lines.sort(key=cmp_to_key(comp))

t = 0
for i in range(len(lines)):
    t += (lines[i][0] * t + lines[i][1]) % 40000

print(t % 40000)