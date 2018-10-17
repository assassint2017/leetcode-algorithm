# 40ms 94.51%
class Solution:
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n is 0:
            return 1.0
        res = 1
        abs_n = abs(n)
        exponential_item = 1
        
        while exponential_item <= abs_n:
            temp = x
            while exponential_item * 2 < abs_n:
                exponential_item *= 2
                temp *= temp
            abs_n -= exponential_item
            exponential_item = 1
            res *= temp

        if n > 0:
            return res
        if n < 0:
            return 1 / res