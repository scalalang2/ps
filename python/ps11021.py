import sys
input = sys.stdin.readline

n = int(input())
for i in range(n):
    a,b = [int(x) for x in input().split()]
    print("Case #%d: %d" % (i+1,a+b))
