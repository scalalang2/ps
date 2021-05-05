import sys 
input = sys.stdin.readline

T = int(input())

# a[j] - j, a[i] - i
for _ in range(T):
    n = int(input())
    cnt = [0 for _ in range(10**5 * 2 + 1)]
    arr = list(map(int, input().split()))

    ans = 0
    for i in range(n):
        el = arr[i] - i
        if i == 0 and el >= 0:
            cnt[el] += 1
        else:
            if el >= 0:
                ans += cnt[el]
                cnt[el] += 1
    
    print(ans)