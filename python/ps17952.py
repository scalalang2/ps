import sys
input = sys.stdin.readline

n = int(input())
subjects = []
score = 0

for i in range(n):
    arr = list(map(int, input().split()))
    if len(arr) > 1:
        # 과제 수행
        arr[2] -= 1
        if arr[2] == 0:
            score += arr[1]
        else:
            subjects.append((arr[1], arr[2]))
    else:
        if len(subjects) > 0:
            s, t = subjects.pop()
            t -= 1
            if t == 0:
                score += s
            else:
                subjects.append((s, t))

print(score)

    