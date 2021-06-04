import sys
input = sys.stdin.readline

n = int(input())

def dfs(st, n):
    if st >= 10:
        for i in range(2, st // 2 + 1):
            # 딱 나누어 떨어지는 수가 있다면 소수 아님
            if st % i == 0:
                return
    
    if st >= 10 ** (n-1):
        print(st)
        return
    
    for i in range(10):
        dfs(st * 10 + i, n)

dfs(2, n)
dfs(3, n)
dfs(5, n)
dfs(7, n)