class Solution(object):
	MOD = 1000000007
    def max_subarray(self, a, size):
        max_so_far = 0
        max_ending_here = 0
        for i in range(size):
            max_ending_here = max_ending_here + a[i]
            if max_so_far < max_ending_here:
                max_so_far = max_ending_here
            if max_ending_here < 0:
                max_ending_here = 0
        return max_so_far
    def kConcatenationMaxSum(self, a, K):
        N = len(a)
        su = max(0, sum(a))
        a += a
        if k < 2:
        	return 
    	return a

sol = Solution()
arr = [ 1, -1, 1 ]
k = 5
print sol.kConcatenationMaxSum(arr, k)