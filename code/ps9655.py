import sys
input = sys.stdin.readline

N = int(input())
arr = [[0 for _ in range(2)] for _ in range(N)]

# arr[i][0] : i번째 턴에 1개를 가져간 경우, 남은 돌의 수
# arr[i][1] : i번째 턴에 3개르 가져간 경우, 남은 돌의 수