import sys
input = sys.stdin.readline

# 일단 문제를 잘 이해해야 한다.
# 무한대로 이용할 수 있는게 아니라
# 무조건 한 번씩만 A,B를 이용해서 붙인다음에
# X를 만들 수 있냐 아니냐만 보는 것

def convert(H, W, S):
    ret = set()
    for i in range(H):
        for j in range(W):
            if S[i][j] == '#':
                ret.add((i, j))
    return ret

def normalize(s):
    my = min(y for (y, x) in s)
    mx = min(x for (y, x) in s)
    return set((y - my, x - mx) for (y, x) in s)

HA, WA = map(int, input().split())
A = [input() for _ in range(HA)]
HB, WB = map(int, input().split())
B = [input() for _ in range(HB)]
HX, WX = map(int, input().split())
X = [input() for _ in range(HX)]

ans = False
A = normalize(convert(HA, WA, A))
B = normalize(convert(HB, WB, B))
X = normalize(convert(HX, WX, X))

# 진짜 이런 테크닉 보면 그냥 파이썬으로 풀고싶어진다니까
for dy in range(-HX, HX):
    for dx in range(-WX, WX):
        ans |= normalize(A.union((y + dy, x + dx) for (y, x) in B)) == X

print("Yes" if ans else "No")