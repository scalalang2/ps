import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
arr.sort()

X = sum(arr[N:N*5-N])
print("%.15f" % (X / (N*3)))


