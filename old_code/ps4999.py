import sys
input = sys.stdin.readline
t1 = input().rstrip()
t2 = input().rstrip()

if len(t1) < len(t2):
    print("no")
else:
    print("go")