import sys
input = sys.stdin.readline

N = int(input())
arr = []

def f(i, N, acc):
    global arr
    if i >= 2:
        size = i // 2
        for j in range(1, size + 1):
            if acc % (10 ** j) == (acc // (10 ** j)) % (10 ** j):
                return
    if i == N:
        print(acc)
        sys.exit(0)
        return
    if i == 0:
        return f(i+1, N, 1)
    else:
        f(i+1, N, acc * 10 + 1)
        f(i+1, N, acc * 10 + 2)
        f(i+1, N, acc * 10 + 3)
        
f(0, N, 0)