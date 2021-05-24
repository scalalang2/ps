import sys
input = sys.stdin.readline

text = input().rstrip()

comb = set([])
ans = []

def dfs(text, i, acc, cnt):
    if i == len(text):
        comb.add(acc)
        return
    
    if text[i] == '(':
        dfs(text, i + 1, acc + text[i], cnt + 1)
        dfs(text, i + 1, acc, cnt)
        return
    
    if text[i] == ')':
        dfs(text, i + 1, acc + text[i])
        dfs(text, i + 1, acc)
        return 
    
    dfs(text, i+1, acc + text[i])

dfs(text, 0, '', 0)

for i in comb:
    stack = []
    if i == text:
        continue

    valid = True
    for j in i:
        if j == '(':
            stack.append('(')
        elif j == ')':
            if len(stack) == 0:
                valid = False
            else:
                stack.pop()
    if len(stack) > 0:
        valid = False
    if valid:
        ans.append(i)

ans.sort()
for el in ans:
    print(el)