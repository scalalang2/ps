import sys
input = sys.stdin.readline

A, B = list(map(int, input().split()))
N, M = list(map(int, input().split()))
robots = []
off_wall = False
crash = False
directions = ['N', 'W', 'S', 'E']

# 한 칸 이동
def forward(x, y, d):
    if d == 'N':
        return x, y + 1
    elif d == 'S':
        return x, y - 1
    elif d == 'W':
        return x - 1, y
    else:
        return x + 1, y

def inrange(x, y):
    if x >= 1 and x <= A and y >= 1 and y <= B:
        return True
    else:
        return False

for _ in range(N):
    x, y, d = input().split()
    _d = 0
    if d == 'N':
        _d = 10 ** 5 * 4
    elif d == 'W':
        _d = 10 ** 5 * 4 + 1
    elif d == 'S':
        _d = 10 ** 5 * 4 + 2
    else:
        _d = 10 ** 5 * 4 + 3
    robots.append((int(x), int(y), _d))

for _ in range(M):
    idx, cmd, repeat = input().split()
    idx = int(idx)
    x, y, d = robots[idx-1]
    if off_wall or crash:
        continue

    for i in range(int(repeat)):
        if cmd == 'F':
            if off_wall or crash:
                continue

            nx, ny = forward(x, y, directions[d % 4])

            if not inrange(nx, ny):
                print("Robot {} crashes into the wall".format(idx))
                off_wall = True
                break

            for j in range(N):
                cx, cy, cd = robots[j]
                if nx == cx and cy == ny and idx != j + 1:
                    print("Robot {} crashes into robot {}".format(idx, j+1))
                    crash = True
                    break

            x = nx
            y = ny
            robots[idx-1] = (nx, ny, d)
        elif cmd == 'L':
            d += 1
            robots[idx-1] = (x, y, d)
        elif cmd == 'R':
            d -= 1
            robots[idx-1] = (x, y, d)

if not(off_wall or crash):
    print("OK")