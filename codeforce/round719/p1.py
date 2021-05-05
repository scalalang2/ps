import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    found = [0 for _ in range(100)]
    N = int(input())
    tasks = input().rstrip()

    prev = tasks[0]
    found[ord(tasks[0]) - ord('A')] = 1
    
    ans = 'YES'

    for i in range(1, len(tasks)):
        if prev == tasks[i]:
            prev = tasks[i]
            continue
        
        ch = ord(tasks[i]) - ord('A')
        if found[ch] == 1:
            ans = 'NO'
            break
        else:
            found[ch] = 1

        prev = tasks[i]
    
    print(ans)