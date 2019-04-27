# Runtime: 24 ms, faster than 69.61% of Python online submissions for Reverse Bits.
# Memory Usage: 11.9 MB, less than 5.38% of Python online submissions for Reverse Bits.

class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        res = 0
        mask = 1

        for i in range(32):
            res <<= 1
            if n & mask:
                res += 1
            mask <<= 1
        
        return res