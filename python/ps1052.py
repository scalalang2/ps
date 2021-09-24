import sys
input = sys.stdin.readline

n, k = list(map(int, input().split()))

if n < k:
    print(0)
else:
    result = 0
    while True:
        cnt = 0
        temp = n
        while temp > 0:
            if temp % 2 == 1:
                cnt += 1
            temp = temp // 2
        if cnt <= k:
            break
        n += 1
        result += 1
    print(result)