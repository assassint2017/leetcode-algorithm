# 思路一的py代码

class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        memo = [False] * 31

        for i in range(31):
            if m == n and m & 1 is 1:
                memo[i] = True
            m >>= 1
            n >>= 1

            if m is 0 and n is 0:
                break
        
        res = 0
        for i in range(30, -1, -1):
            res <<= 1
            if memo[i]:
                res += 1
        
        return res
    
# 思路二的py代码

# Runtime: 60 ms, faster than 86.48% of Python3 online submissions for Bitwise AND of Numbers Range.
# Memory Usage: 13.4 MB, less than 21.68% of Python3 online submissions for Bitwise AND of Numbers Range.

class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        
        if m is 0 and n is 0:
            return 0
        
        factor = 0
        while m != n:
            m >>= 1
            n >>= 1
            factor += 1
        
        return m << factor