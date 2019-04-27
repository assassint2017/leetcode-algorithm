# Runtime: 36 ms, faster than 9.72% of Python online submissions for Number of 1 Bits.
# Memory Usage: 11.7 MB, less than 5.10% of Python online submissions for Number of 1 Bits.

class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        res = 0
        while n > 0:
            if n & 1 is 1:
                res += 1
            n >>= 1
        return res
        