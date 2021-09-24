# 문제 조건을 잘 봐야함
# 1번과 2번 사람만을 재량껏 통과시켜줄 수 있음

import sys
input = sys.stdin.readline

diff = int(input())
lines = input().rstrip()
stack = []

for i in range(len(lines) - 1, -1, -1):
    stack.append(lines[i])

mans = 0
womans = 0
flag = False

while len(stack) > 0:
    if abs(mans - womans) > diff:
        flag = True
        break
    if len(stack) == 0:
        break
    elif len(stack) == 1:
        el = stack.pop()
        if el == 'M':
            mans += 1
        else:
            womans += 1
        if abs(mans - womans) > diff:
            flag = True
    else:
        a = stack.pop()
        b = stack.pop()

        if mans > womans and a == 'W':
            womans += 1
            stack.append(b)
        elif mans > womans and b == 'W':
            womans += 1
            stack.append(a)
        elif womans > mans and a == 'M':
            mans += 1
            stack.append(b)
        elif womans > mans and b == 'M':
            mans += 1
            stack.append(a)
        else:
            if a == 'M':
                mans += 1
                stack.append(b)
            else:
                womans += 1
                stack.append(b)

if flag:
    print(mans + womans - 1)
else:
    print(mans + womans)