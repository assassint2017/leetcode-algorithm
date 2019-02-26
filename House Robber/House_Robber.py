# Runtime: 44 ms, faster than 34.83% of Python3 online submissions for House Robber.
# Memory Usage: 13.1 MB, less than 5.00% of Python3 online submissions for House Robber.

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) is 0:
            return 0
        
        res = [0 for i in range(len(nums))]

        res[-1] = nums[-1]
        if len(nums) >= 2:
            res[-2] = max(nums[-1], nums[-2])
        if len(nums) >= 3:
            res[-3] = max(nums[-1] + nums[-3], nums[-2])
        
        for i in range(len(nums) - 4, -1, -1):
            res[i] = max(nums[i] + res[i + 2], nums[i + 1] + res[i + 3])
        
        return res[0]