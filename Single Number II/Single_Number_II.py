# Runtime: 140 ms, faster than 7.26% of Python3 online submissions for Single Number II.
# Memory Usage: 14.1 MB, less than 68.49% of Python3 online submissions for Single Number II.

class Solution:
    def singleNumber(self, nums) -> int:
        
        memo = [0 for i in range(32)]
        temp = 1
        
        for index in range(32):
            for number in nums:
                memo[index] += ((temp & number) >= 1)
            memo[index] %= 3

            temp <<= 1
        
        if memo[31] is 1:
            found = False
            for index in range(31):
                if memo[index] is 1:
                    found = True
                    memo[index] = 0
                    index -= 1
                    while(index >= 0):
                        memo[index] = 1
                        index -= 1
                    break
            if not found:
                return -(2 ** 31)
            for i in range(31):
                memo[i] = int(memo[i] == 0)
        
        res = 0
        for index in range(30, -1, -1):
            res <<= 1
            res += memo[index]
        
        return res if memo[31] == 0 else -res