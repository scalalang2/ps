import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
 
n, m = map(int, input().split())
par = [i for i in range(n+1)]
 
def find(x):
    if par[x] == x:
        return x
    else:
        par[x] = find(par[x])
        return par[x]
    
def merge(x, y):
    px = find(x)
    py = find(y)
    if px == py:
        return
    par[py] = px
 
for _ in range(m):
    x, y = map(int, input().split())
    merge(x, y)
 
bad = False
bad_table = {}
 
k = int(input())
for _ in range(k):
    x, y = map(int, input().split())
    if find(x) == find(y):
        bad = True
    else:
        bad_table[str(find(x)) + ":" + str(find(y))] = True
        bad_table[str(find(y)) + ":" + str(find(x))] = True
 
q = int(input())
for _ in range(q):
    x, y = map(int, input().split())
    if bad:
        print("No")
    else:
        if str(find(x)) + ":" + str(find(y)) in bad_table:
            print("No")
        else:
            print("Yes")