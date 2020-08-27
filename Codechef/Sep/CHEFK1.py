import math
t = 1
for i in range(1, 10):
	t = str(i) + "|\t"
	for j in range(1, 46):
		n, m = i, j
		p = n * (n+1) / 2

		if n-1 > m or p < m or m == 0:
			t += "0" + "\t"
		elif m == 1:
			t += "1" + "\t"
		elif n+1 >= m:
			t += "2" + "\t"
		elif 2*n >= m:
			t += "3" + "\t"
		else:
			m -= 2*n
			r = n
			if n&1:
				x = m % n
				z = 2 if n/2 < x else 1
				if x == 0:
					z = 0
				t += str(3 + 2*(m/n) + z) + "\t"
			else:
			    t += str(3 + (m + n/2-1)/(n/2)) + "\t"
	print t
# t = []

# n, m = [15, 17]
# p = n * (n+1) / 2
# if n-1 > m or m == 0:
# 	t.append(-1)
# elif m == 1:
# 	t.append(1)
# elif n+1 >= m:
# 	t.append(2)
# elif 2*n >= m:
# 	t.append(3)
# else:
# 	c = 3
# 	m -= 2*n
# 	d = n/2
# 	while m > 0:
# 		m -= d
# 		c += 1
# 	t.append(min(c, n))
# print t