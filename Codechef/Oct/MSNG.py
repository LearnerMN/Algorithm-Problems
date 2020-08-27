from collections import defaultdict

MAX_BASE = 37

def val(c): 
    if c >= '0' and c <= '9': 
        return ord(c) - ord('0') 
    else: 
        return ord(c) - ord('A') + 10; 
  
def toDeci(str,base): 
    llen = len(str) 
    power = 1
    num = 0
  
    for i in range(llen - 1, -1, -1): 
        if val(str[i]) >= base:
            return -1
        num += val(str[i]) * power 
        power = power * base 
    return num

def findAns(code, n):
    mp = defaultdict(int)
    for a, b in code.items():
        for i in set(b):
            mp[i] += 1
    # print mp
    for a, b in sorted(mp.items()):
        if b == n and a <= 10**12:
            return a
    return -1

t = int(raw_input())
for i in range(0, t):
    n = int(raw_input())
    code = defaultdict(list)
    for j in range(0, n):
        a, b = raw_input().split()
        a = int(a)
        if a == -1:
            for k in range(2, MAX_BASE):
                tmp = toDeci(b, k)
                if tmp != -1:
                    code[j].append(tmp)
        else:
            code[j].append(toDeci(b, a))
    print findAns(code, n)