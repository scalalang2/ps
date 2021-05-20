import sys
from heapq import heappush, heappop
input = sys.stdin.readline

D_UP = 1
D_DOWN = 2
D_RIGHT = 3
D_LEFT = 4

R, C, M = list(map(int,input().split()))
sharks = []
ans = 0

for _ in range(M):
    r, c, s, d, z = list(map(int, input().split()))
    sharks.append({
        "r": r,
        "c": c,
        "speed": s,
        "direction": d,
        "size": z,
        "catched": False,
        "valid": True
    })

def catch_neareast(col):
    global ans, sharks
    min_index = -1
    min_value = R + 1

    for i in range(len(sharks)):
        # 상어가 잡아 먹히지 않았으며
        # 컬럼이 동일하고
        # 값이 작은 경우
        if sharks[i]['catched'] == False and sharks[i]['valid'] and sharks[i]['c'] == col and sharks[i]['r'] < min_value:
            min_value = sharks[i]['r']
            min_index = i

    if min_index != -1:
        sharks[min_index]['catched'] = True
        ans += sharks[min_index]['size']

def move_sharks():
    global sharks, R, C

    # 모든 상어를 이동
    for i in range(len(sharks)):
        el = sharks[i]
        if el['catched'] == True or el['valid'] == False:
            continue

        if el['direction'] == D_UP or el['direction'] == D_DOWN:
            moves = el['speed']

            while moves > 0:
                if el['direction'] == D_DOWN and el['r'] + moves > R:
                    moves -= R - el['r']
                    el['r'] = R
                    el['direction'] = D_UP
                elif el['direction'] == D_DOWN and el['r'] + moves <= R:
                    el['r'] = el['r'] + moves
                    moves = 0
                elif el['direction'] == D_UP and el['r'] - moves < 1:
                    moves -= el['r'] - 1
                    el['r'] = 1
                    el['direction'] = D_DOWN
                elif el['direction'] == D_UP and el['r'] - moves >= 1:
                    el['r'] = el['r'] - moves
                    moves = 0
        else:
            moves = el['speed']

            while moves > 0:
                if el['direction'] == D_RIGHT and el['c'] + moves > C:
                    moves -= C - el['c']
                    el['c'] = C
                    el['direction'] = D_LEFT
                elif el['direction'] == D_RIGHT and el['c'] + moves <= C:
                    el['c'] = el['c'] + moves
                    moves = 0
                elif el['direction'] == D_LEFT and el['c'] - moves < 1:
                    moves -= el['c'] - 1
                    el['c'] = 1
                    el['direction'] = D_RIGHT
                elif el['direction'] == D_LEFT and el['c'] - moves >= 1:
                    el['c'] = el['c'] - moves
                    moves = 0
    
    # 겹치는 상어는 제거
    queue = []
    for i in range(len(sharks)):
        if sharks[i]['valid'] == False or sharks[i]['catched'] == True:
            continue
        heappush(queue, (sharks[i]['r'], sharks[i]['c'], i))
    
    prev = None
    while len(queue) > 0:
        if prev == None:
            prev = heappop(queue)
        else:
            c_r, c_c, c_i = heappop(queue)
            p_r, p_c, p_i = prev

            if c_r == p_r and c_c == p_c:
                if sharks[c_i]['size'] > sharks[p_i]['size']:
                    sharks[p_i]['valid'] = False
                    prev = (c_r, c_c, c_i)
                else:
                    sharks[c_i]['valid'] = False
            else:
                prev = (c_r, c_c, c_i)

def start(col_size):
    for i in range(col_size):
        # 가장 가까운 상어를 찾는다
        catch_neareast(i+1)

        # 상어가 이동한다.
        move_sharks()

start(C)
print(ans)