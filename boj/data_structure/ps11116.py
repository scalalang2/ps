import sys
input = sys.stdin.readline

t = int(input())
while t > 0:
    m = int(input())
    ans = 0
    checked = [False for _ in range(m)]
    left = list(map(int, input().split()))
    right = list(map(int, input().split()))

    for i in range(m):
        if checked[i]:
            continue
        checked[i] = True
        bits = 0
        for j in range(i+1, m):
            if left[j] == left[i] + 500:
                bits = bits | (1 << 2)
        for j in range(m):
            if right[j] == left[i] + 1000:
                bits = bits | (1 << 1)
            if right[j] == left[i] + 1500:
                bits = bits | (1 << 0)
        if bits == 7:
            ans += 1
    print(ans)
    t -= 1