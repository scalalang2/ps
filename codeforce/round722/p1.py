import sys
input = sys.stdin.readline

t = int(input())

while t > 0:
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    ans = 0
    temp = 0

    for i in range(n):
        temp += arr[i]
        cnt = i + 1
        if arr[i] > temp // cnt:
            ans += 1
            temp -= arr[i]
    
    print(ans)
    t -= 1