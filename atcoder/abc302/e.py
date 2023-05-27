import sys
input = sys.stdin.readline

N, Q = list(map(int, input().split()))

# 맵으로 관리하는거 어떻게 생각해
indeg = [0] * (N+1)
ans = N

# 0 이면 비연결
# 1 이면 연결
adj = [set([]) for _ in range(N+1)]

for i in range(Q):
    cmd = list(map(int, input().split()))
    if cmd[0] == 1:
        adj[cmd[1]].add(cmd[2])
        adj[cmd[2]].add(cmd[1])
        # print("add", cmd[1], cmd[2], indeg[cmd[1]], indeg[cmd[2]])
        if indeg[cmd[1]] == 0:
            ans -= 1
        
        if indeg[cmd[2]] == 0:
            ans -= 1

        indeg[cmd[1]] += 1
        indeg[cmd[2]] += 1

    if cmd[0] == 2:
        if indeg[cmd[1]] != 0:
            ans += 1
            indeg[cmd[1]] = 0
        for x in adj[cmd[1]]:
            adj[x].discard(cmd[1])
            indeg[x] -= 1
            # print(indeg[x])
            if indeg[x] == 0:
                ans += 1
        
        adj[cmd[1]] = set([])
    
    print(ans)
