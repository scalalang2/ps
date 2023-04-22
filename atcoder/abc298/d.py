import sys
from collections import deque
input = sys.stdin.readline
 
MOD = 998244353
QUO = 0
S = 1
digits = 1
Q = int(input())
 
for _ in range(Q):
    order = list(map(int, input().split()))
    if order[0] == 1:
        S = (S * 10 + order[1])
        if S >= MOD:
            QUO += 1
            S %= MOD
        digits += 1
    elif order[0] == 2:
        S = QUO * MOD + S
        S -= 10 ** (digits - 1)
        digits -= 1
        if S >= MOD:
            QUO += 1
            S %= MOD
    else:
        print(S % MOD)