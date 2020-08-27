import math

def two_pow(y):
    number = 1
    x = 2
    while y:
        if y & 1:
            number = number * x
        y >>= 1
        x = x * x
    return number

n = 3 # int(raw_input())
arr = [1, 2, 5] #list(map(int, raw_input().split()))
q = 1

mp = {}
for i in range(1, 1000001):
	t = 0
	for x in arr:
		if x>i or i%x != 0:
			t += 1
	mp[i] = two_pow(n) - two_pow(t)

for i in range(0, q):
	k = 5
	print mp[k]