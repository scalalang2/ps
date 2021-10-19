import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n = int(input())
adj = [[] for _ in range(n+1)]
nodes = ['' for _ in range(n+1)]
p = [-1 for _ in range(n+1)]

def find(a):
    if p[a] < 0:
        return a
    else:
        p1 = find(p[a])
        p[a] = p1
        return p1

def union(a, b):
    _a = find(a)
    _b = find(b)
    if _a == _b:
        return
    p[_a] += p[_b]
    p[_b] = _a

for i in range(n-1):
    u, v = list(map(int, input().split()))
    adj[u].append(v)
    adj[v].append(u)

txt = input().rstrip()
for i in range(1, n+1):
    nodes[i] = txt[i-1]

for i in range(1, n+1):
    if nodes[i] == 'R':
        for nxt in adj[i]:
            if nodes[nxt] == 'R':
                union(i, nxt)

ans = 0
for i in range(1, n+1):
    if nodes[i] == 'B':
        for nxt in adj[i]:
            if nodes[nxt] == 'R':
                a = find(nxt)
                ans += p[a] * -1
print(ans)