import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N, K = map(int, input().split())
    S = input().strip()

    if S == S[::-1]:
        print("Yes")
    elif N % 3 != 0:
        print("No")
    else:
        k = N // 3
        if S[:k] == S[len(S)-k:len(S)] and S[:k] == S[k:len(S)-k][::-1] and K % N == N // 3:
            print("Yes")
        else:
            print("No")