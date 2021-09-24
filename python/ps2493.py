import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
stack = []
ans = []

for i in range(n):
    if i == 0:
        ans.append(0)
        stack.append((arr[i], i))
        continue

    while len(stack) > 0 and stack[len(stack)-1][0] < arr[i]:
        stack.pop()
    
    if len(stack) == 0:
        ans.append(0)
    else:
        ans.append(stack[len(stack)-1][1] + 1)

    stack.append((arr[i], i))

print(' '.join(list(map(str, ans))))