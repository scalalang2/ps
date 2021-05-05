import sys
input = sys.stdin.readline

N = int(input())
# 다리 배열
# - [1, 1]
# - [1, 2]

# 1 - 2 - 3
# arr[i] = i번째 다리가 이어져있는지?
# 추가 당시 이전, 이후에 값이 없다면 + 2, 값이 하나라도 전재하면 + 1
# 임의의 섬 (i, j) 이동거리의 최소 비용의 합
# nC2 n! / r!(n-r)!
# [1, 1, 1, 1]
# 1, 2, 3, 4, 5
# 4 + 3 + 3 + 2 + 2 + 2 + 1 + 1 + 1 + 1
# N * (N-1) + (N-1)


for _ in range(N-1):
    k = int(input())