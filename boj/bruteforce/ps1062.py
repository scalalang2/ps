import sys
from itertools import combinations
input = sys.stdin.readline

n, k = list(map(int, input().split()))
literals = ['b','d','e','f','g','h','j','k','l','m','n','o','p','q','r','s','u','v','w','x','y','z']
checked = []

def init():
    global literals
    global checked

    checked = [0 for _ in range(26)]
    checked[ord('a') - ord('a')] = 1
    checked[ord('n') - ord('a')] = 1
    checked[ord('t') - ord('a')] = 1
    checked[ord('i') - ord('a')] = 1
    checked[ord('c') - ord('a')] = 1

arr = []
for _ in range(n):
    arr.append(input().rstrip())

def find():
    ans = 0
    for text in arr:
        flag = True
        for i in range(len(text)):
            if checked[ord(text[i]) - ord('a')] == 0:
                flag = False
        if flag:
            ans += 1
    return ans

if k < 5:
    print(0)
elif k == 5:
    init()
    print(find())
else:
    ans = 0
    for el in combinations(literals, k - 5):
        init()
        for i in range(len(el)):
            checked[ord(el[i]) - ord('a')] = 1
        ans = max(ans, find())
    print(ans)
