import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    red, blue, differ = list(map(int, input().split()))
    if red < blue:
        if blue - red > red * differ:
            print("NO")
        else:
            print("YES")
    else:
        if red - blue > blue * differ:
            print("NO")
        else:
            print("YES")