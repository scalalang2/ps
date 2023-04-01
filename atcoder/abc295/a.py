import sys
input = sys.stdin.readline
x = ["and", "not", "that", "the", "you"]

n = int(input())
ss = map(str, input().split())
for s in ss:
    if s in x:
        print("Yes")
        exit(0)

print("No")