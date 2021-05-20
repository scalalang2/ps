import sys
input = sys.stdin.readline

# 80,000
N = int(input())
stack = []
ans = 0

for i in range(N):
    v = int(input())
    while len(stack) > 0 and stack[len(stack)-1] <= v:
        stack.pop()

    stack.append(v)
    ans += len(stack) - 1
    
print(ans)