import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    N = int(input())
    adj = [[] for _ in range(N+1)]

    # 다음 노드를 계속 연결함
    for tries in range(N):
        arr = list(map(int, input().split()))
        for i in range(0, len(arr)-1):
            adj[arr[i]].append(arr[i+1])

    printed = False
    def dfs(node, acc, visited):
        global printed
        if printed:
            return

        if acc == N and not printed:
            printed = True
            print(" ".join(map(str, visited)))
            return
        
        for next_node in adj[node]:
            dfs(next_node, acc+1, visited + [next_node])
    
    for i in range(N):
        dfs(i+1, 1, [i+1])