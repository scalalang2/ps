import sys
input = sys.stdin.readline

n = int(input())
S = input()

st = S[0]

for i in range(1, len(S)):
    if(S[i] == st):
        print("No")
        exit()
    st = S[i]

print("Yes")