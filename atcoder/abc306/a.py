import sys
input = sys.stdin.readline

n = int(input())
X = input()
ans = ""
for i in X:
    ans += i * 2

print(ans)