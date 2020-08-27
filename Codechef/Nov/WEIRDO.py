from collections import defaultdict

def is_vowel(ch):
    return (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u')

def power(x, y): 
  
    if(y == 0): return 1
    temp = power(x, int(y / 2))  
      
    if (y % 2 == 0): 
        return temp * temp 
    else: 
        if(y > 0): return x * temp * temp 
        else: return (temp * temp) / x 

def checker(s):

    n = len(s)
    c = 0
    for i in range(0, n):
        check = is_vowel(s[i])
        c += check
        if ((not check) and i-1 >= 0 and (not is_vowel(s[i-1]))):
            return False
        
        if ((not check) and i-2 >= 0 and (not is_vowel(s[i-2]))):
            return False
        
    return int((n+1)/2) <= c

t = int(input())
i = 0
while i < t:
    n = int(input())
    a = 0
    b = 0
    mpA = [0.0]*26
    mpB = [0.0]*26
    mpAC = [0.0]*26
    mpBC = [0.0]*26

    k = 0
    while k < n:
        s = input()

        c = 0
        sp = [0]*26
        l = len(s)
        z = 0
        while z < l:
            sp[ord(s[z])-97] += 1
            z += 1
        is_a = checker(s)
        if is_a:
            a += 1
            x = 0
            while x < 26:
                if sp[x] > 0:
                    mpAC[x] += 1
                    mpA[x] += sp[x]
                x += 1
        else:
            b += 1
            x = 0
            while x < 26:
                if sp[x] > 0:
                    mpBC[x] += 1
                    mpB[x] += sp[x]
                x += 1
        k += 1
    A = 1.0
    B = 1.0

    x = 0
    while x < 26:
        if mpA[x] > 0:
            A *= mpAC[x]/power(mpA[x], a)
        
        if mpB[x] > 0:
            B *= mpBC[x]/power(mpB[x], b)

        x += 1

    if B == 0:
        print ("Infinity")
    else:
        ratio = A/B
        if ratio > 10000000:
            print ("Infinity")
        else:
            print ("{0:7f}".format(ratio))

    i += 1



