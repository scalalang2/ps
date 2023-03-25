import math

def f(n, b):
    while n > 0:
        if n % b > 1:
            return False
        n //= b
    return True

def solve(n):
    max_base = math.ceil(math.log(n, 2))
    min_base = 3
    ans = 1
    s = set([2])
    for b in range(min_base, max(min_base,max_base)+1):
        if f(n, b):
            ans += 1
            s.add(b)
    
    if max_base < n-1:
        if (n-1) >= 2 and (n-1) not in s:
            ans += 1
        if n >= 2 and n not in s:
            ans += 1

    return ans

t = int(input())
for _ in range(t):
    n = int(input())
    print(solve(n))
