import sys
input = sys.stdin.readline

max_index = 0
max_value = 0
for i in range(9):
    el = int(input())
    if el >= max_value:
        max_value = el
        max_index = i + 1

print(max_value)
print(max_index)
