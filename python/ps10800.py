import sys
input = sys.stdin.readline

N = int(input())
acc = 0
colors = [0 for _ in range(N+1)]
sizes = [0 for _ in range(2001)]
ans = [0 for _ in range(N)]
arr = []

for i in range(N):
    color, size = [int(x) for x in input().split()]
    arr.append((size, color, i))

arr.sort()

j = 0
for i in range(N):
    size, color, idx = arr[i]
    b = arr[j]
    
    # 누적 크기 - 본인 색상의 누적 크기 - 본인과 같은 크기의 누적 크기
    while b[0] < size:
        acc += b[0]
        colors[b[1]] += b[0]
        j += 1
        b = arr[j]

    ans[idx] = acc - colors[color]

for el in ans:
    print(el)