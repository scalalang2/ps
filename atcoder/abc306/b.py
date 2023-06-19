import sys
input = sys.stdin.readline

X = list(map(int, input().split()))
ans = 0
for i in range(len(X)):
    if X[i] == 1:
        ans += pow(2, i)

print(ans)
    