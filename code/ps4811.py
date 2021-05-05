import sys 
input = sys.stdin.readline

d = [[0 for _ in range(33)] for _ in range(33)]

for h in range(31):
    for w in range(31):
        # 작은 알약이 큰 알약보다 많을 수는 없다.
        if h > w:
            continue
        if h == 0:
            d[w][h] = 1
        else:
            d[w][h] = d[w][h-1] + d[w-1][h]

while True:
    n = int(input())
    if n == 0:
        break
    print(d[n][n])