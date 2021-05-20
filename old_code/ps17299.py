import sys
from collections import defaultdict
input = sys.stdin.readline

N = int(input())
answer = [0 for _ in range(N)]
arr = list(map(int, input().split()))
freq = defaultdict(int)
stack = []

for num in arr:
    freq[num] = freq[num] + 1

for i in range(len(arr)-1 , -1, -1):
    if len(stack) == 0:
        answer[i] = -1
        stack.append((freq[arr[i]], arr[i]))
        continue
    
    head_freq, head = stack[len(stack) - 1]
    while len(stack) > 0 and head_freq <= freq[arr[i]]:
        stack.pop()
        if len(stack) > 0:
            head_freq, head = stack[len(stack) - 1]
    
    if len(stack) == 0:
        answer[i] = -1
    else:
        answer[i] = head

    stack.append((freq[arr[i]], arr[i]))

print(' '.join(list(map(str, answer))))