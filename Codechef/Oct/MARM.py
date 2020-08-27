t = int(raw_input())
for i in range(0, t):
	n, k = list(map(int, raw_input().split()))
	v = list(map(int, raw_input().split()))
	k = k % (n*3) + n*3
	for i in range(0, k):
		v[i % n] = v[i % n] ^ v[n - i%n - 1]
	print ' '.join(v)