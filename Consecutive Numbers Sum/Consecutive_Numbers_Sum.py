# Runtime: 220 ms, faster than 49.53% of Python3 online submissions for Consecutive Numbers Sum.
# Memory Usage: 13.3 MB, less than 5.00% of Python3 online submissions for Consecutive Numbers Sum.

class Solution:
    def consecutiveNumbersSum(self, N: int) -> int:
        res = 0
        m = 1
        while True:
            temp = 2 * N - (m - 1) * m
            if temp <= 0:
                break
            if temp % (2 * m) is 0:
                res += 1
            m += 1
        return res