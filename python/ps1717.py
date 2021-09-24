import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

n, m = [int(x) for x in input().split()]
p = [i for i in range(n+1)]

def find(x):
    # self return or root인 경우
    if p[x] == x:
        return x
    else:
        p[x] = find(p[x])
        return p[x]

def union(a,b):
    a = find(a)
    b = find(b)
    if a == b:
        return
    p[a] = b

for _ in range(m):
    c, u, v = [int(x) for x in input().split()]
    if c == 0:
        union(u,v)
    else:
        if find(u) == find(v):
            print("YES")
        else:
            print("NO")