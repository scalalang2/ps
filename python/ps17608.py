import sys
input = sys.stdin.readline

n = int(input())
stack = []
for _ in range(n):
    stack.append(int(input()))

ans = 1
ret = stack.pop()

while len(stack) > 0:
    a = stack.pop()
    if a > ret:
        ans += 1
        ret = a

print(ans)