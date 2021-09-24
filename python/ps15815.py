# 그냥 후위표기식 계산 문제
import sys
input = sys.stdin.readline

text = input().rstrip()
stack = []

for i in range(len(text)):
    if text[i] == '*':
        a = stack.pop()
        b = stack.pop()
        stack.append(b * a)
    elif text[i] == '+':
        a = stack.pop()
        b = stack.pop()
        stack.append(b + a)
    elif text[i] == '-':
        a = stack.pop()
        b = stack.pop()
        stack.append(b - a)
    elif text[i] == '/':
        a = stack.pop()
        b = stack.pop()
        stack.append(b // a)
    else:
        stack.append(int(text[i]))
    
print(stack[0])