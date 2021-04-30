import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    students = [[] for _ in range(n)]
    univ = list(map(int, input().split()))
    scores = list(map(int, input().split()))

    for i in range(n):
        students[univ[i]-1].append(scores[i] * -1)
    
    prefixSum = [[] for _ in range(n)]
    answer = [0 for _ in range(n)]
    for i in range(n):
        students[i].sort()
        for j in range(len(students[i])):
            el = (prefixSum[i][j-1] + students[i][j] * -1) if j > 0 else students[i][j] * -1
            prefixSum[i].append(el)

        for j in range(len(students[i])):
            point = (j+1) * (len(students[i]) // (j+1))
            if point != 0:
                answer[j] += prefixSum[i][point-1]

    print(' '.join(list(map(str, answer))))