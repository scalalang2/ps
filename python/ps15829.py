import sys
input = sys.stdin.readline

r = 31
m = 1234567891

n = int(input())
text = input().rstrip()
ans = 0

for i in range(len(text)):
    ans += (ord(text[i]) - ord('a') + 1) * (r ** i)
    ans %= m

print(ans)