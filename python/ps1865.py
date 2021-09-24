import sys
input = sys.stdin.readline

MAX = 10 ** 10
TestCase = int(input())

while TestCase > 0:
    TestCase -= 1

    N, M, W = list(map(int, input().split()))
    graph = [[ MAX for _ in range(N) ] for _ in range(N) ]
    for i in range(M):
        S, E, T = list(map(int, input().split()))
        graph[S-1][E-1] = min(graph[S-1][E-1], T)
        graph[E-1][S-1] = min(graph[E-1][S-1], T)
    
    for i in range(W):
        S, E, T = list(map(int, input().split()))
        graph[S-1][E-1] = min(graph[S-1][E-1], T * -1)
    
    dist = [ MAX for _ in range(N) ]
    negative_cycle = False
    for i in range(N):
        # 존재하는 모든 Edge에서 Edge Relaxation을 해주기 위해 for문을 3개를 쓴다.
        for j in range(N):
            for k in range(N):
                if dist[k] > dist[j] + graph[j][k]:
                    dist[k] = dist[j] + graph[j][k]
                    if i == N-1:
                        negative_cycle = True
    
    if negative_cycle:
        print("YES")
    else:
        print("NO")