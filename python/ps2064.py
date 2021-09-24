import sys
input = sys.stdin.readline

iparr = [1 for _ in range(32)]

def make_addr(bits):
    ret = []
    num = 0
    for i in range(32):
        if bits & ((1 << 31) >> i) >= 1:
            num += 1
        num <<= 1
        if (i+1) % 8 == 0:
            ret.append(str(num >> 1))
            num = 0

    return ".".join(ret)

n = int(input())
addr = []
for _ in range(n):
    ip = input().rstrip()
    addr.append(ip.split("."))

for j in range(n-1):
    for k in range(4):
        num = int(addr[j-1][k]) ^ int(addr[j][k])
        for l in range(8):
            if num & ((1 << 7) >> l) >= 1:
                iparr[(k * 8 + l)] = 0

mask = 0
flag = True
for i in range(32):
    if flag and iparr[i] == 1:
        mask += iparr[i]
    else:
        flag = False
        mask += 0
    if i != 31:
        mask <<= 1

bits = 0
for k in range(4):
    num = int(addr[0][k])
    for l in range(8):
        if num & ((1 << 7) >> l) >= 1:
            bits += 1
        bits <<= 1

print(make_addr((bits >> 1) & mask))
print(make_addr(mask))
