import sys
input = sys.stdin.readline

while True:
    text = input().rstrip()
    if text == '.':
        break
    
    valid = True
    stack = []
    for i in range(len(text)):
        if text[i] == '(' or text[i] == '[':
            stack.append(text[i])
        elif text[i] == ')' or text[i] == ']':
            if len(stack) == 0:
                valid = False
                continue
            s = stack.pop()
            if not ((s == '(' and text[i] == ')') or (s == '[' and text[i] == ']')):
                valid = False
                continue
    
    if len(stack) > 0:
        valid = False
    
    if valid:
        print("yes")
    else:
        print("no")