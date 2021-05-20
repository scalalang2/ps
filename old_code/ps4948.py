import sys
input = sys.stdin.readline

MAX = 123456 * 2 + 1
table = [False for _ in range(MAX)]
table[1] = True
for i in range(2, MAX):
    st = i
    while st + i <= MAX:
        st += i
        table[st] = True

while True:
    n = int(input())
    if n == 0:
        break
    cnt = 0
    for i in range(n+1, 2*n + 1):
        if not table[i]:
            cnt += 1
    print(cnt)