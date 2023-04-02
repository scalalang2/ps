import sys
input = sys.stdin.readline

table = [input() for i in range(8)]
for i in range(8):
    for j in range(8):
        if(table[i][j] == '*'):
            print('{}{}'.format(chr(ord('a') + j), 8-i))