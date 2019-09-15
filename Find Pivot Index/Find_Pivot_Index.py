# Runtime: 176 ms, faster than 61.16% of Python3 online submissions for Find Pivot Index.
# Memory Usage: 14.9 MB, less than 8.33% of Python3 online submissions for Find Pivot Index.

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        rightSum = sum(nums)

        leftSum = 0

        for index in range(len(nums)):
            rightSum -= nums[index]
            if index > 0:
                leftSum += nums[index - 1]
            if leftSum == rightSum:
                return index
        
        return -1