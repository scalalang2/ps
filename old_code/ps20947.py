import sys
from bisect import bisect_left, bisect_right

input = sys.stdin.readline
N = int(input())

world = []
rows = [[] for _ in range(N)]
cols = [[] for _ in range(N)]

for i in range(N):
    line = input().rstrip()
    world.append(line)
    for j in range(N):
        if line[j] == 'O' or line[j] == 'X':
            rows[i].append(j)
            cols[j].append(i)

for i in range(N):
    text = ''
    for j in range(N):
        if not world[i][j] == '.':
            text += world[i][j]
            continue
        
        rl = bisect_left(rows[i], j)
        cl = bisect_left(cols[j], i)
        flag = True
        txt = ''

        if rl != len(rows[i]):
            txt += world[i][rows[i][rl]]

        if len(rows[i]) > 0 and rl - 1 >= 0:
            txt += world[i][rows[i][rl-1]]
            
        if cl != len(cols[j]):
            txt += world[cols[j][cl]][j]

        if len(cols[j]) > 0 and cl - 1 >= 0:
            txt += world[cols[j][cl-1]][j]
        
        for k in range(len(txt)):
            if not txt[k] == 'X':
                flag = False

        if flag and len(txt) > 0:
            text += 'B'
        else:
            text += '.'
    print(text)