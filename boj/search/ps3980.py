import sys
input = sys.stdin.readline

T = int(input())
PLAYERS = 11
scores = [[0 for _ in range(PLAYERS)] for _ in range(PLAYERS)]
ans = 0
all_chk = 0

for i in range(PLAYERS):
    all_chk = all_chk + (1 << i)

def dfs(player, chk, agg):
    global ans

    if player == PLAYERS:
        ans = max(ans, agg)
        return
    
    for pos in range(PLAYERS):
        if (1 << pos) & chk > 0:
            continue

        if scores[player][pos] == 0:
            continue
        
        dfs(player + 1, chk | (1 << pos), agg + scores[player][pos])


def run():
    global ans
    
    ans = 0
    for i in range(PLAYERS):
        arr = [int(x) for x in input().split()]
        for j in range(PLAYERS):
            scores[i][j] = arr[j]
    
    dfs(0, 0, 0)

    print(ans)

for _ in range(T):
    run()