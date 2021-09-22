import sys
input = sys.stdin.readline


def go():
    if n == 1:
        print('A')
        return
    if n == 2:
        if x[0] == x[1]:
            print(x[0])
            return
        else:
            print('A')
            return

    if x[0] == x[1]:
        a = 0
    else:
        a = (x[2] - x[1])//(x[1] - x[0])

    b = x[1] - a * x[0]

    for i in range(n-1):
        nxt = a * x[i] + b
        if x[i+1] != nxt:
            print('B')
            return

    print(a * x[-1] + b)
    return


n = int(input())
x = list(map(int, input().split()))

go()