from collections import defaultdict

def counter(dic):
	fOdd = 0
	fEven = 0;
	for f, s in mpX.items:
	    if s & 1:
	        fOdd += 1
	    else:
	        fEven += 1
	return [fOdd, fEven]

t = int(raw_input())
for i in range(0, t):
	n, m, q = list(map(int, raw_input().split()))
	mpX = defaultdict(bool)
	mpY = defaultdict(bool)
	for k in range(0, q):
		x, y = list(map(int, raw_input().split()))
		mpX[x] = not mpX[x]
		mpY[y] = not mpY[y]

	fO, fE = counter(mpX)
	sO, sE = counter(mpY)

	res = fO * sE + sO * fE + fO * (m - len(mpY)) + sO * (n - len(mpX))
	print res