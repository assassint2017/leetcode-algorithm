# 48ms 87.3%
class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for index in range(1, len(nums)):
            if nums[index - 1] > 0:
                nums[index] += nums[index - 1]
        return max(nums)