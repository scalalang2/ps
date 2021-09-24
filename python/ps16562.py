import sys
input = sys.stdin.readline

n,m,k = [int(x) for x in input().split()]
cost = [int(x) for x in input().split()]
p = [i for i in range(n+1)]

def find(a):
    if p[a] == a:
        return a
    else:
        p[a] = find(p[a])
        return p[a]

def union(a, b):
    _a = find(a)
    _b = find(b)
    if _a == _b:
        return
    if cost[_a-1] > cost[_b-1]:
        p[_a] = _b
    else:
        p[_b] = _a

for _ in range(m):
    u,v = list(map(int, input().split()))
    union(u,v)

roots = set([])
for i in range(n+1):
    pnode = find(i)
    if pnode != 0:
        roots.add(pnode)

ans = 0
for el in roots:
    ans += cost[el-1]

if ans > k:
    print("Oh no")
else:
    print(ans)