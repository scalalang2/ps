import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))

    avg = sum(arr) // len(arr)
    over_cnt = 0
    over_sum = 0
    under_sum = 0

    for i in range(len(arr)):
        if arr[i] > avg:
            over_cnt += 1
            over_sum += arr[i] - avg
        else:
            under_sum += avg - arr[i]

    if over_sum == 0:
        print(0)
    elif over_sum == under_sum:
        print(over_cnt)
    else:
        print(-1)