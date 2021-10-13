import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    arr = [int(x) for x in input().split()]
    m = {}

    a = []
    
    for el in arr:
        if el in m:
            continue
        else:
            a.append(el)
            m[el] = 1
    
    flag = True
    a.sort()
    if len(a) == 1:
        print(0)
        continue
    elif len(a) == 2:
        print(a[0] - a[1])
        continue
    else:
        diff = a[0] - a[1]
        for i in range(2, len(a)):
            if diff != a[i-1] - a[i]:
                flag = False
        
    if flag:
        print(abs(diff))
    else:
        print(-1)
