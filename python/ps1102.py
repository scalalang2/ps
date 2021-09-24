import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

INF = 10 ** 10
n = int(input())
dp = [-1 for _ in range(1 << 16)]
cost = []

for _ in range(n):
    cost.append([int(x) for x in input().split()])

initial_status = input().rstrip()

# 적어도 p개의 발전소가 고장나면 안됨
p = int(input())

def f(num, status):
    if num == p:
        return 0
    if dp[status] != -1:
        return dp[status]
    
    dp[status] = INF
    for _from in range(n):
        # 현재 비트가 켜져있는 경우에 그 비용을 이용해서 구함
        if (status & (1 << _from)) == 1:
            for to in range(n):
                # 같은 발전소라면 건너뛴다.
                if _from == to:
                    continue

                # 발전소가 꺼져 있는 상태라면 켜져있는 i에서 j를 킨다.
                if (status & (1 << to)) == 0:
                    dp[status] = min(dp[status], f(num + 1, status | (1 << to)) + cost[_from][to])
    
    return dp[status]

cnt = 0
cur = 0
for i in range(len(initial_status)):
    if initial_status[i] == 'Y':
        cur = cur | (1 << i)
        cnt += 1

if cnt == 0:
    if p == 0:
        print(0)
    else:
        print(-1)
elif cnt >= p:
    print(0)
else:
    print(f(cnt, cur))