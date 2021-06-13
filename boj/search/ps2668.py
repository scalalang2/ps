import sys
input = sys.stdin.readline

n = int(input())
arr = [0 for _ in range(n+1)]
visited = [False for _ in range(n+1)]

ans = []
for i in range(n):
    arr[i+1] = int(input())

def check_cycle(start, curr):
    global visited
    global ans

    if visited[curr] and start == curr:
        ans.append(start)
        return
    elif not visited[curr]:
        visited[curr] = True
        check_cycle(start, arr[curr])

for i in range(n):
    visited = [False for _ in range(n+1)]
    visited[i+1] = True
    check_cycle(i+1, arr[i+1])

print(len(ans))
for el in ans:
    print(el)