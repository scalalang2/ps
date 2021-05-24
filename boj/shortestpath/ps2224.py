import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
graph = [[False for _ in range(52)] for _ in range(52)]
answer = []

def to_chr(num):
    if num > 25:
        return chr(num + 97 - 26)
    else:
        return chr(num + 65)

def to_ord(text):
    if 'A' <= text <= 'Z':
        return ord(text) - 65
    else:
        return ord(text) - 97 + 26

for i in range(n):
    S, arrow, T = input().rstrip().split()
    S = to_ord(S)
    T = to_ord(T)
    graph[S][T] = True

for k in range(52):
    for i in range(52):
        for j in range(52):
            if graph[i][k] and graph[k][j]:
                graph[i][j] = True

cnt = 0
answer = []

for i in range(52):
    for j in range(52):
        if graph[i][j] and i != j:
            cnt += 1
            answer.append(to_chr(i) + " => " + to_chr(j))
print(cnt)
for el in answer:
    print(el)