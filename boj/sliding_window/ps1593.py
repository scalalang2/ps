import sys
input = sys.stdin.readline

N, M = [int(x) for x in input().split()]
W = input().rstrip()
S = input().rstrip()

prime_number = 17
hashed = 0
match_hash = 0
ans = 0

for el in W:
    hashed += ord(el) ** prime_number

if N <= M:
    for i in range(N):
        match_hash += ord(S[i]) ** prime_number
    
    if match_hash == hashed:
        ans += 1
    
    for i in range(N, M):
        match_hash -= ord(S[i-N]) ** prime_number
        match_hash += ord(S[i]) ** prime_number

        if match_hash == hashed:
            ans += 1
    
    print(ans)
else:
    print(0)
