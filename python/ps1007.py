import sys
import math
from itertools import combinations

input = sys.stdin.readline

def dist(x1, x2, y1, y2):
    return math.sqrt((x2-x1) ** 2 + (y2-y1) ** 2)

T = int(input())
for _ in range(T):
    n = int(input())
    
    ans = sys.maxsize

    sumx = 0
    sumy = 0
    coords = []

    for _ in range(n):
        x, y = [int(x) for x in input().split()]
        sumx += x
        sumy += y
        coords.append((x, y))

    comb = combinations(coords, n//2)
    for com in comb:
        tempx = 0
        tempy = 0
        for x,y in com:
            tempx += x
            tempy += y

        ans = min(ans, dist(tempx, sumx-tempx, tempy, sumy-tempy))
    
    print(ans)