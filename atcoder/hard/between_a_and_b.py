import sys
from collections import deque
input = sys.stdin.readline
 
a,b,c = map(int, input().split())
ans = 0
 
def f(n):
    if n == -1:
        return 0
    
    return n // c + 1
 
ans += f(b) - f(a-1)
print(ans)