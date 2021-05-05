import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    n = input().rstrip()
    temp = ''
    for i in range(len(n)):
        temp += n[0]
    
    if int(n) < 10:
        print(n)
    elif int(n) >= int(temp):
        print(9 * (len(n)-1) + int(n[0]))
    else:
        print(9 * (len(n)-1) + int(n[0])-1)