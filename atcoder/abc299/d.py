import sys
input = sys.stdin.readline

arr = [-1] * 200002
n = int(input())

arr[1] = 0
arr[n] = 1
if n == 2:
    print("! 1")
    exit(0)

low = 1
high = n

while low <= high:
    mid = (low + high) // 2

    # 물어 봤어
    print("? {}".format(mid))
    sys.stdout.flush()

    x = int(input())
    arr[mid] = x
    if x == 0:
        low = mid + 1
    else:
        high = mid - 1
    
    if arr[mid] != -1 and arr[mid+1] != -1 and arr[mid] != arr[mid+1] and mid != n:
        print("! {}".format(mid))
        exit(0)
    if arr[mid] != -1 and arr[mid-1] != -1 and arr[mid] != arr[mid-1]:
        print("! {}".format(mid-1))
        exit(0)