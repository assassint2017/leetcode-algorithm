# 二分查找法
# 36ms 98.77%
class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left, right = 0, len(nums) - 1
        while right - left > 1:
            mid = (left + right) // 2
            if nums[mid] <= target:
                left = mid
            else:
                right = mid - 1
        
        if target <= nums[left]:
            return left
        elif target <= nums[right]:
            return left + 1
        else:
            return right + 1