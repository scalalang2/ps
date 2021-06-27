import sys
input = sys.stdin.readline

N = 9
board = [[0 for _ in range(9)] for _ in range(9)]
state = False

def print_board():
    for el in board:
        print(''.join(list(map(str, el))))

def search_empty():
    for i in range(N):
        for j in range(N):
            if board[i][j] == 0:
                return i,j
    return None, None

def dfs():
    global board
    global state

    row, column = search_empty()
    if row == None:
        state = True
        return

    chk = [-1 for _ in range(10)]
    for k in range(9):
        if board[row][k] != 0:
            chk[board[row][k]] = 1
        if board[k][column] != 0:
            chk[board[k][column]] = 1
    
    for r in range((row // 3) * 3, (row // 3) * 3 + 3):
        for c in range((column // 3) * 3 , (column // 3) * 3 + 3):
            if board[r][c] != 0:
                chk[board[r][c]] = 1

    for i in range(1, 10):
        if chk[i] == -1:
            board[row][column] = i
            dfs()
            if state:
                break
            board[row][column] = 0

for i in range(9):
    num = int(input())
    j = 8
    while j >= 0:
        board[i][j] = num % 10
        num = num // 10
        j -= 1

dfs()
print_board()