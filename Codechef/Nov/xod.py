def to_bits(n):
  return '{0:08b}'.format(n)

def reverse_num_bits(num):
  arr = [0]*32
  ind = 31
  while num > 0:
  	arr[ind] = num&1
  	num = num>>1
  	ind -= 1

  res = 0
  for i in range(31, -1, -1):
  	res += arr[i]*pow(2, i)
  	
  return res

print(to_bits(1234))
# 10011010010
print(reverse_num_bits(1234))
# 1260388352
print(to_bits(reverse_num_bits(1234)))
# 1001011001000000000000000000000