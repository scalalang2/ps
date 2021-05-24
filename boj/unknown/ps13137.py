import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
answer = True

if n == 1:
    if arr[0] != 1:
        print("No")
    else:
        print("Yes")
else:
    for i in range(1, n):
        if arr[i] % arr[i-1] != 0:
            answer = False

    if answer:
        print("Yes")
    else:
        print("No")