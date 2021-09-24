import sys
input = sys.stdin.readline

i = 1
while True:
    L, P, V = list(map(int, input().split()))
    if L == 0 and P == 0 and V == 0:
        break
    ans = (V % P)
    ans = (V // P) * L
    if (V % P) < L:
        ans += (V % P)
    else:
        ans += L
    print("Case %d: %d" % (i, ans))

    i += 1

# 2 8 20
# 0 0 0