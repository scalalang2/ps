from collections import defaultdict
T = int(input())
for _ in range(T):
    N = int(input())
    arr = []
    for i in range(N):
        arr.append(int(input()))

    ans = 1
    while True:
        flag = True
        checked = defaultdict(bool)
        for i in range(len(arr)):
            if not checked[arr[i] % ans]:
                checked[arr[i] % ans] = True
            else:
                flag = False
                break
        if flag:
            break
        ans += 1

    print(ans)