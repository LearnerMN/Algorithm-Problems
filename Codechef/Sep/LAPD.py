from collections import defaultdict
t = 1
for i in range(0, t):
	res = 0
	mp = defaultdict(int)
	A, B, C = [1, 2, 3]
	for b in range(1, B+1):
		for a in range(1, A+1):	
			for c in range(1, C+1):
				if b*b< (a-1)*(c-1):
					# print b, (a-1), (c-1)
					res += 1
	print res

