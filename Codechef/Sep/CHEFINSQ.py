import math 
from collections import defaultdict
t = int(raw_input())
for i in range(0, t):
	n, k = list(map(int, raw_input().split()))
	mp = defaultdict(int)
	arr = list(map(int, raw_input().split()))
	for a in arr:
		mp[a] += 1
	res = 1
	for a, c in mp.items():
		print a, c
		if c < k:
			k -= c
		elif c == k:
			res = 1
			break
		else:
			res = (math.factorial(c) / (math.factorial(c - k) * math.factorial(k)));
			break
	print res