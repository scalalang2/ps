import sys
from collections import defaultdict

input = sys.stdin.readline

A = input().rstrip()
B = input().rstrip()

# 교집합 개수 찾기
def intersection(A, B):
    dict_A = defaultdict(int)
    dict_B = defaultdict(int)
    cnt = 0

    for el in A:
        dict_A[el] = dict_A[el] + 1

    for el in B:
        dict_B[el] = dict_B[el] + 1
    
    for el in A:
        cnt += min(dict_A[el], dict_B[el])
    
    return cnt

print(intersection(A, B))