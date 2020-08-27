import math 
from collections import defaultdict

MOD = 1000000007

def modFact(n): 
    if n >= MOD: 
        return 0    
  
    result = 1
    for i in range(1, n + 1): 
        result = (result * i) % MOD
  
    return result 

n, k = list(map(int, raw_input().split()))
arr = list(map(int, raw_input().split()))
res = 1
for i in range(1, k+1):
	print(modFact(n) / (modFact(n - i) * modFact(i)))
	res = (res + (modFact(n) / (modFact(n - i) * modFact(i)))) % MOD
print res
