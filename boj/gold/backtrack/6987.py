import sys
input = sys.stdin.readline

from itertools import combinations

comb = list(combinations(range(6), 2))
wins = [0 for _ in range(6)]
draws = [0 for _ in range(6)]
loses = [0 for _ in range(6)]

def f(idx):
    if idx == len(comb):
        return (sum(wins) + sum(draws) + sum(loses)) == 0
    
    a, b = comb[idx]
    if wins[a] > 0 and loses[b] > 0:
        wins[a] -= 1
        loses[b] -= 1
        if f(idx+1):
            return True
        wins[a] += 1
        loses[b] += 1
    if draws[a] > 0 and draws[b] > 0:
        draws[a] -= 1
        draws[b] -= 1
        if f(idx+1):
            return True
        draws[a] += 1
        draws[b] += 1
    if loses[a] > 0 and wins[b] > 0:
        loses[a] -= 1
        wins[b] -= 1
        if f(idx+1):
            return True
        loses[a] += 1
        wins[b] += 1

    return False
        

for _ in range(4):
    arr = list(map(int, input().split()))
    for i in range(6):
        wins[i] = arr[i*3]
        draws[i] = arr[i*3+1]
        loses[i] = arr[i*3+2]

    if f(0):
        print(1, end=' ')
    else:
        print(0, end=' ')