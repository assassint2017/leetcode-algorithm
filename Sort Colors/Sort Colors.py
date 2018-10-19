# 48ms 39.41%
class Solution:
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        index, left, right = 0, 0, len(nums) - 1
        while index <= right:
            if nums[index] is 0 and index != left:
                nums[index], nums[left] = nums[left], nums[index]
                left += 1
            elif nums[index] is 2 and index != right:
                nums[index], nums[right] = nums[right], nums[index]
                right -= 1
            else:
                index += 1