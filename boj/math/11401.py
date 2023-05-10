import sys
input = sys.stdin.readline

N, K = map(int, input().split())
MOD = 1000000007

NF = 1
RF = 1
N_RF = 1

for i in range(2, N+1):
    NF *= i
    NF %= MOD

for i in range(2, K+1):
    RF *= i
    RF %= MOD

for i in range(2, N-K+1):
    N_RF *= i
    N_RF %= MOD

X = RF * N_RF % MOD
X = pow(X, MOD-2, MOD)

print(NF * X % MOD)