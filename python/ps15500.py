# n 이 최대 123 밖에 되지 않으므로 얼추 N^2으로 풀어도 정답임
# 즉, 최대값을 계속 찾아다니면 됨

import sys
input = sys.stdin.readline

n = int(input())
stack1 = list(map(int, input().split()))
stack2 = []
stack3 = []
cmd = []

while len(stack3) < n:
    stack1_max = 0 if len(stack1) == 0 else max(stack1)
    stack2_max = 0 if len(stack2) == 0 else max(stack2)

    if stack1_max > stack2_max:
        if stack1[len(stack1) - 1] == stack1_max:
            stack3.append(stack1.pop())
            cmd.append((1, 3))
        else:
            stack2.append(stack1.pop())
            cmd.append((1, 2))
    else:
        if stack2[len(stack2) - 1] == stack2_max:
            stack3.append(stack2.pop())
            cmd.append((2, 3))
        else:
            stack1.append(stack2.pop())
            cmd.append((2, 1))

print(len(cmd))
for el in cmd:
    _from, _to = el
    print(_from, _to)