import math

T = int(raw_input())

for t in range(0, T):
	ind = int(raw_input())

	o = int(math.sqrt(ind))
	if o*o == ind:
		print "1"*ind
	else:

		pre = 0
		bod = ind
		if ind > 5:
			bod = ind/100
			pre = ind - bod
		x = 0
		for i in range(0, bod):
			x = x*10 + 1
		b = x*9+1
		res = "0"
		while x < b:
			r = 0
			n = x
			while n > 0:
				d = n % 10
				if d == 0:
					r = -1
					break
				r += d*d
				n /= 10

			if r != -1:
				z = int(math.sqrt(r))
				if z*z == r:
					res = str(x)
					break
			x += 1
		res = "1"*pre + res
		print (res)