import sys
input = sys.stdin.readline

text = input().rstrip();
b1, b2, r1, r2, k = -1,-1,-1,-1,-1


for i in range(len(text)):
    if text[i] == 'R':
        if r1 == -1:
            r1 = i
        else:
            r2 = i
    elif text[i] == 'B':
        if b1 == -1:
            b1 = i
        else:
            b2 = i
    elif text[i] == 'K':
        k = i

if r1 < k and k < r2 and (b1 % 2) != (b2 % 2):
    print("Yes")
else:
    print("No")