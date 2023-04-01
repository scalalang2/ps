import sys
from collections import Counter

input = sys.stdin.readline

s = input().strip()
ans = 0
for i in range(2, len(s), 2):
