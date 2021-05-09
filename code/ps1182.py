import sys
input = sys.stdin.readline

N, S = list(map(int, input().split()))
arr = list(map(int, input().split()))
cnt = 0

def dfs(i, acc):
    global cnt

    if i == N:
        return
    if acc + arr[i] == S:
        cnt += 1
    
    dfs(i + 1, acc)
    dfs(i + 1, acc + arr[i])

dfs(0, 0)
print(cnt)