import sys
input = sys.stdin.readline

n = int(input())

psum = [0 for _ in range(n+1)]
psum[1] = 1

for i in range(2, n+1):
    psum[i] = psum[i-1] + (i-1)

print(psum[n-1]*2)