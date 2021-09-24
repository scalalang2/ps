import sys
input = sys.stdin.readline

n, k = list(map(int, input().split()))
num = input().rstrip()
stack = []
deleted = 0

for i in range(n):
    if i == 0:
        stack.append(num[i])
        continue

    while len(stack) > 0 and int(stack[len(stack)-1]) < int(num[i]):
        if deleted == k:
            break
        stack.pop()
        deleted += 1
    
    stack.append(num[i])

while deleted < k:
    stack.pop()
    deleted += 1

print(int(''.join(stack)))