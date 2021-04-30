import sys
input = sys.stdin.readline

N, M, T = list(map(int, input().split()))
matrix = []
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# 회전
def rotate(arr, k, d):
    if d == 0:
        return arr[M-k:] + arr[:M-k]
    else:
        return arr[k:] + arr[:k]

for _ in range(N):
    matrix.append(list(map(int, input().split())))

for _ in range(T):
    x, d, k = list(map(int, input().split()))
    for i in range(N // x):
        _n = (i+1) * x
        matrix[_n-1] = rotate(matrix[_n-1], k, d)

    deleted = [[False for _ in range(M)] for _ in range(N)]
    for i in range(N):
        for j in range(M):
            if matrix[i][j] == 0:
                continue

            for _k in range(4):
                nx = j + dx[_k]
                ny = i + dy[_k]

                if ny < 0 or ny >= N:
                    continue

                if nx < 0:
                    nx = M-1
                elif nx == M:
                    nx = 0

                if matrix[i][j] == matrix[ny][nx]:
                    deleted[i][j] = True
                    deleted[ny][nx] = True
    
    flag = False
    _cnt = 0
    _sum = 0
    for i in range(N):
        for j in range(M):
            if deleted[i][j]:
                flag = True
                matrix[i][j] = 0
            elif matrix[i][j] != 0:
                _cnt += 1
                _sum += matrix[i][j]
        
    if flag == False:
        if _cnt != 0:
            avg = _sum / _cnt
            for i in range(N):
                for j in range(M):
                    if matrix[i][j] != 0 and matrix[i][j] < avg:
                        matrix[i][j] += 1
                    elif matrix[i][j] > avg:
                        matrix[i][j] -= 1
    
ans = 0
for i in range(N):
    for j in range(M):
        ans += matrix[i][j]

print(ans)