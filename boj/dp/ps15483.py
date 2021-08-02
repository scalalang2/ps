import sys
input = sys.stdin.readline

a = input().rstrip()
b = input().rstrip()

dist = [[0 for _ in range(len(b) + 1)] for _ in range(len(a) + 1)]

for i in range(len(a) + 1):
    dist[i][0] = i

for i in range(len(b) + 1):
    dist[0][i] = i

for i in range(1, len(a) + 1):
    for j in range(1, len(b) + 1):
        if a[i-1] == b[j-1]:
            dist[i][j] = dist[i-1][j-1]
        else:
            dist[i][j] = 1 + min(dist[i-1][j-1], dist[i-1][j], dist[i][j-1])

print(dist[len(a)][len(b)])