# Runtime: 40 ms, faster than 100.00% of Python3 online submissions for Factorial Trailing Zeroes.
# Memory Usage: 12.5 MB, less than 46.24% of Python3 online submissions for Factorial Trailing Zeroes.

class Solution:
    def trailingZeroes(self, n: 'int') -> 'int':
        sum = 0
        while n > 0:
            sum += (n // 5)
            n //= 5
        return sum