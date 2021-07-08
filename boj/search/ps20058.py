import sys
sys.setrecursionlimit(10 ** 4)
input = sys.stdin.readline

N, Q = [int(x) for x in input().split()]
table = []
table.append([0 for _ in range(2 ** N + 2)])
for i in range(2**N):
    el = [0]
    el.extend([int(x) for x in input().split()])
    el.append(0)
    table.append(el)
table.append([0 for _ in range(2 ** N + 2)])
visit = [[0 for _ in range(2 ** N + 2)] for _ in range(2 ** N + 2)]

L = [int(x) for x in input().split()]
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

# r = 회전 행 위치
# c = 회전 열 위치 
# size = 격자의 크기
def rotate(r, c, size):
    global table

    temp = [[0 for _ in range(size)] for _ in range(size)]
    for i in range(size):
        for j in range(size):
            temp[j][size - i - 1] = table[r + i][c + j]
    
    for i in range(size):
        for j in range(size):
            table[r + i][c + j] = temp[i][j]

# 얼음 녹이기
def meltdown():
    temp = [[0 for _ in range(2 ** N + 2)] for _ in range(2 ** N + 2)]
    
    for i in range(1, (2 ** N) + 1):
        for j in range(1, (2 ** N) + 1):
            if table[i][j] == 0:
                continue
            cnt = 0
            for k in range(4):
                nx = j + dx[k]
                ny = i + dy[k]
                if table[ny][nx] > 0:
                    cnt += 1
            
            if cnt < 3:
                temp[i][j] = table[i][j] - 1
            else:
                temp[i][j] = table[i][j]
    
    return temp

def sum_of_ice():
    ret = 0
    for i in range(1, (2 ** N) + 1):
        ret += sum(table[i])
    return ret

# 최대 덩어리 찾기
def find_maximum(r, c):
    global visit
    visit[r][c] = 1
    ret = 1
    for k in range(4):
        ny = r + dy[k]
        nx = c + dx[k]

        if visit[ny][nx] == 0 and table[ny][nx] > 0:
            ret += find_maximum(ny, nx)
    return ret

def debug_table():
    for i in range(0, (2**N)+2):
        print(table[i])

for step in range(Q):
    size = 2 ** L[step]
    for r in range(1, 2 ** N + 1, size):
        for c in range(1, 2 ** N + 1, size):
            rotate(r, c, size)
    
    temp = meltdown()
    for i in range(1, 2 ** N + 1):
        for j in range(1, 2 ** N + 1):
            table[i][j] = temp[i][j]

max_ice = 0
for i in range(1, (2 ** N) + 1):
    for j in range(1, (2 ** N) + 1):
        if table[i][j] > 0 and visit[i][j] == 0:
            max_ice = max(max_ice, find_maximum(i, j))

print(sum_of_ice(), max_ice)