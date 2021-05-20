import sys
input = sys.stdin.readline

text = input().rstrip()
ans = 0

# 괄호 스택
stack = []

def top():
    return stack[len(stack)-1]

def is_brace(ch):
    return ch == ']' or ch == '[' or ch == '(' or ch == ')'

for i in range(len(text)):
    if text[i] == '(' or text[i] == '[':
        stack.append(text[i])
    else:
        if len(stack) == 0:
            print(0)
            sys.exit(0)
        
        head = top()
        if head == '(' and text[i] == ')':
            stack.pop()
            stack.append(2)
        elif head == '[' and text[i] == ']':
            stack.pop()
            stack.append(3)
        else:
            _sum = 0
            while len(stack) > 0 and not is_brace(top()):
                op = stack.pop()
                if text[i] == ')':
                    _sum += op * 2
                elif text[i] == ']':
                    _sum += op * 3

            if len(stack) == 0:
                print(0)
                sys.exit(0)
            head = top()
            if not ((head == '(' and text[i] == ')') or (head == '[' and text[i] == ']')):
                print(0)
                sys.exit(0)
            stack.pop()

            stack.append(_sum)

try:
    print(sum(stack))
except:
    print(0)

    