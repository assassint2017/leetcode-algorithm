# Runtime: 32 ms, faster than 89.32% of Python3 online submissions for Number of Digit One.
# Memory Usage: 13.9 MB, less than 100.00% of Python3 online submissions for Number of Digit One.

class Solution:
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        if n <= 0:
            return 0
        
        base = 10
        count = 0
        while n // base > 0:
            base *= 10
            count += 1
        base /= 10

        high = n // base
        res = 0

        if high is 1:
            res += n - high * base + 1
        else:
            res += base
        
        res += high * count * (base / 10)

        return res + self.countDigitOne(n - high * base)