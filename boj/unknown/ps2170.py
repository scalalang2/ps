import sys
input = sys.stdin.readline

n = int(input())
arr = []
for _ in range(n):
    st, ed = list(map(int, input().split()))
    arr.append((st, ed))
arr.sort()

ret = 0
st = -1
ed = -1

for i in range(n):
    if i == 0:
        st = arr[i][0]
        ed = arr[i][1]
    else:
        if st <= arr[i][0] <= ed:
            if arr[i][1] > ed:
                ed = arr[i][1]
        else:
            ret += ed - st
            st = arr[i][0]
            ed = arr[i][1]

ret += ed - st
print(ret)
