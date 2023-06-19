import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
given = {}

vec = []

for i in range(3*n):
    if arr[i] in given and given[arr[i]] == 1:
        vec.append((i+1, arr[i]))
        given[arr[i]] += 1
    else:
        given[arr[i]] = 1
        
vec.sort()
for i in range(len(vec)):
    print(vec[i][1], end=" ")