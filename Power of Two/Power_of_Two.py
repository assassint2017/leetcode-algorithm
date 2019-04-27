# Runtime: 36 ms, faster than 100.00% of Python3 online submissions for Power of Two.
# Memory Usage: 13.2 MB, less than 6.20% of Python3 online submissions for Power of Two.
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n <= 0:
            return False
        else:
            return not (n - 1) & n