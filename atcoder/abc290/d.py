# x0 = (a + d)%n 
# x1 = (x0 + d)%n = (a + 2d)%n
# x2 = (x1 + d)%n = (a + 3d)%n
# x3 = (x2 + d)%n = (a + 4d)%n
# x4 = (x3 + d)%n = (a + 5d)%n
# (a + pd) % n
#
# p 번 반복해야만 다시 x0이 나온다고 치자.
# 그러면 다음에는 x0+1을해서 다시 p번 뺑뺑이 돌린다.
# 숫자가 존나거 시부랭
# 일단 저기서는 겹치는게 없다는게 확신이 드는데 그 다음엔 어떻하지?
# 무조건 달라지는게 보장되나..? 아마 그럴지도..?
# 그래야지만 계산이 되서 풀 수 있을 거 같은데?

import sys
input = sys.stdin.readline

def find_p(a, d, n):
    if (a + 2*d)%n == (a+d)%n:
        return 1

    p = 2
    while True:
        if (a+d)%n == (a+(d*p))%n:
            return p
        p += 1

T = int(input())
ans = [0,2,1,3,0,3,1,4,2]
ndks = []

for i in range(T):
    n, d, k = map(int, input().split())
    ndks.append((n, d, k))

for a in range(-100, 100, 1):
    for b in range(-100, 100, 1):
        if a == 0 and b == 0:
            print("..?")
        ansb = []
        for n, d, k in ndks:
            P = find_p(0, d, n)
            ansb.append(((k+a)//P + ((k+b)%P)*d)%n)
        
        if ans == ansb:
            print(a, b, ans, ansb)
            break
