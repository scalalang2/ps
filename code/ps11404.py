# 플로이드 와샬
# d[i][j] = d[i][k] + d[k][j]
# i~k 까지의 최단 경로 + k ~ j 까지의 최단 경로를 합한게 d[i][j]보다 작아야 한다. => 업데이트
import sys
input = sys.stdin.readline

INF = 1000000000000000000

# 도시의 수
V = int(input())

# 버스의 수
E = int(input())

graph = [[] for _ in range(V + 1)]
dist = [[INF for _ in range(V + 1)] for _ in range(V + 1)]

for i in range(1, V+1):
    dist[i][i] = 0

for _ in range(E):
    u, v, c = list(map(int, input().split()))
    dist[u][v] = min(dist[u][v], c)

for k in range(1, V+1):
    for i in range(1, V+1):
        for j in range(1, V+1):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

for i in range(1, V+1):
    arr = []
    for j in range(1, V+1):
        el = dist[i][j] if dist[i][j] != INF else 0
        arr.append(str(el))

    print(' '.join(arr))