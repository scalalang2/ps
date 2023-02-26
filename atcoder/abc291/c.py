import sys
input = sys.stdin.readline

N = int(input())
S = input().rstrip()
X = {}

coords = [0, 0];
flag = False
def to_s(x):
    return "/".join(map(str,x))

X[to_s(coords)] = True

for i in range(N):
    if S[i] == 'R':
        coords[0] += 1
    elif S[i] == 'L':
        coords[0] -= 1
    elif S[i] == 'U':
        coords[1] += 1
    elif S[i] == 'D':
        coords[1] -= 1
    
    if to_s(coords) in X:
        flag = True
    
    X[to_s(coords)] = True

print("Yes" if flag else "No")