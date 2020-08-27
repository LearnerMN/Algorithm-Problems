from collections import defaultdict

def groupAnagramWords(strs):
	# Fill this in.
	mp = defaultdict(list)
	for s in strs:
		mp[''.join(sorted(s))].append(s)
	res = []
	for a, b in mp.items():
		res += [b]
	return res

print groupAnagramWords(['abc', 'bcd', 'cba', 'cbd', 'efg'])
# [['efg'], ['bcd', 'cbd'], ['abc', 'cba']]