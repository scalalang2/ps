import sys
input = sys.stdin.readline

B = 0
R = 1

t = int(input())
ans = []
for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    x = input().rstrip()

    arr = []
    for i in range(n):
        c = B if x[i] == 'B' else R
        arr.append([abs(a[i]), c, False if a[i] < 0 else True])
    
    arr.sort()
    nxt = 1
    flag = True

    for el in arr:
        num = el[0]
        c = el[1]
        positive = el[2]
        
        if c == B and num >= nxt and positive:
            nxt += 1
        elif c == R and not positive:
            nxt += 1
        elif c == R and num <= nxt and positive:
            nxt += 1
        else:
            flag = False
            break;
    
    if flag:
        ans.append("YES")
    else:
        ans.append("NO")

for el in ans:
    print(el)