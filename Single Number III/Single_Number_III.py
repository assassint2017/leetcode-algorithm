# Runtime: 56 ms, faster than 24.38% of Python3 online submissions for Single Number III.
# Memory Usage: 14.4 MB, less than 46.00% of Python3 online submissions for Single Number III.

class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        if len(nums) < 2:
            return []
        
        res = 0
        for num in nums:
            res ^= num
        
        temp = 1
        while True:
            if temp & res:
                res = temp
                break
            else:
                temp <<= 1
        
        res1, res2 = 0, 0
        for num in nums:
            if res & num:
                res1 ^= num
            else:
                res2 ^= num
        
        num = []
        num.append(res1)
        num.append(res2)

        return num