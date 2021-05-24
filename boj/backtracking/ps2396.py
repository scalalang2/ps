import sys
input = sys.stdin.readline

n = int(input())
visited = [False for _ in range(n)]
sticks = list(map(int, input().split()))
if n == 0:
    print(0)
    sys.exit()

_sum = sum(sticks)
sticks.sort(reverse=True)
flag = False

def dfs(num, length, st, temp):
    global visited

    if num == _sum // temp:
        return True
    sample = -1
    for i in range(st, n):
        # 이미 선택한 막대인 경우 건너뛰기
        if visited[i] or sticks[i] == sample:
            continue
        visited[i] = True
        # 작으면 다음 스틱을 더하기
        if length + sticks[i] < temp:
            if dfs(num, length + sticks[i], i+1, temp):
                return True
            else:
                sample = sticks[i]
        # 큰거 부터 조합하자 맞으면 건너뛰기
        elif length + sticks[i] == temp:
            if dfs(num+1, 0, 0, temp):
                return True
            else:
                sample = sticks[i]
        visited[i] = False
        if length == 0:
            break
    return False

for temp in range(sticks[0], _sum):
    if _sum % temp == 0:
        if dfs(0, 0, 0, temp):
            print(temp)
            flag = True
            break

if not flag:
    print(_sum)