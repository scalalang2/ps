import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, x, t = list(map(int, input().split()))
    ans = n * ((t // x)) - (((t//x) * (t//x + 1)) // 2)
    print(ans)