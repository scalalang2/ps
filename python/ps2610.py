import sys
input = sys.stdin.readline

MAX = 10 ** 6
N = int(input())
M = int(input())

graph = [[ MAX for _ in range(N+1) ] for _ in range(N+1)]
visited = [ False for _ in range(N+1) ]
cnt = 0
answer = []

for _ in range(M):
    u, v = list(map(int, input().split()))
    graph[u][v] = 1
    graph[v][u] = 1

for i in range(1, N + 1):
    graph[i][i] = 1

for k in range(N+1):
    for i in range(N+1):
        for j in range(N+1):
            if graph[i][j] > graph[i][k] + graph[k][j]:
                graph[i][j] = graph[i][k] + graph[k][j]

for k in range(1, N+1):
    if visited[k]:
        continue
    cnt += 1
    ret = 0
    short_path = MAX
    temp = []

    for i in range(1, N+1):
        if graph[k][i] == MAX:
            continue
        visited[k] = True
        visited[i] = True

        temp.append(i)
    
    for i in range(len(temp)):
        temp_val = 0
        for j in range(len(temp)):
            temp_val = max(graph[temp[j]][temp[i]], temp_val)

        if short_path > temp_val:
            short_path = temp_val
            ret = temp[i]

    answer.append(ret)

print(cnt)
answer.sort()
for el in answer:
    print(el)
