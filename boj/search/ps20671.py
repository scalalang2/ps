import sys
input = sys.stdin.readline

n = int(input())
arr = [(0, 0, 0)]
adj = [[] for _ in range(n+1)]
indeg = [0 for _ in range(n+1)]

for i in range(n):
    h, l, r = [int(x) for x in input().split()]
    arr.append((h, l, r))

arr.sort()

def binleft(low, high, l, r):
    while low <= high:
        mid = (low + high) // 2
        if arr[mid][1] <= l and r <= arr[mid][2]:
            return mid
        else:
            if l < arr[mid][1]:
                high = mid - 1
            else:
                low = mid + 1
    return 0

def make_tree():
    global adj
    global indeg

    prev, left, right, new_left, new_right = 0, 0, 0, 1, 1
    cnt = 1
    for i in range(1,n+1):
        h, l, r = arr[i]
        if h == 1:
            adj[0].append(i)
            adj[i].append(0)
            if cnt == 1:
                new_left, new_right = i, i
            else:
                new_right += 1
            cnt += 1
            continue

        if prev != h:
            prev = h
            left = new_left
            right = new_right
            new_left = i
            new_right = i
        
        p = binleft(left, right, l, r)
        adj[p].append(i)
        adj[i].append(p)
        indeg[p] += 1
        new_right += 1

X = int(input())
for i in range(X):
    pos, power = [int(x) for x in input().split()]

make_tree()