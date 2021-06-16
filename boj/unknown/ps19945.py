n = int(input())
cnt = 31
while n & (1 << cnt) == 0 and cnt > 0:
    cnt -= 1

if n == 0:
    print(1)
elif n < 0:
    print(32)
else:
    print(cnt+1)