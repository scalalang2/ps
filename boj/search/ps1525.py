import sys
from collections import defaultdict, deque
input = sys.stdin.readline

start_state = ''
target_state = '123456780'
state = defaultdict(int)
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for _ in range(3):
    a, b, c = [x for x in input().split()]
    start_state += a + b + c

def make_num(table):
    ret = ''

    for i in range(3):
        for j in range(3):
            ret += str(table[i][j])
    
    return ret

def next_state(num):
    # 0 을 찾는다.
    # 찾은 0을 가지고 다음 상태로 변경한 0<s<4 개의 상태를 찾는다.
    table = [['' for _ in range(3)] for _ in range(3)]
    next_state = []
    zero_y, zero_x = 0, 0

    for i in range(3):
        for j in range(3):
            table[i][j] = num[i*3 + j]
            if num[i*3 + j] == '0':
                zero_y = i
                zero_x = j
    
    for k in range(4):
        ny = zero_y + dy[k]
        nx = zero_x + dx[k]

        if nx < 0 or nx >= 3 or ny < 0 or ny >= 3:
            continue
        
        table[zero_y][zero_x] = table[ny][nx]
        table[ny][nx] = 0
        next_state.append(make_num(table))
        table[ny][nx] = table[zero_y][zero_x]
        table[zero_y][zero_x] = 0
    
    return next_state

def bfs(num):
    global state
    queue = deque([])
    queue.append(num)

    while len(queue) > 0:
        curr = queue.popleft()
        nxt_states = next_state(curr)
        
        for nxt in nxt_states:
            if state[nxt] != 0:
                continue
            state[nxt] = state[curr] + 1
            queue.append(nxt)

state[start_state] = 1
bfs(start_state)
print(state[target_state] - 1)