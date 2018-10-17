# 第一种思路
# 76ms 60.32%
class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        index = 1
        while index < len(nums):
            if nums[index] == nums[index - 1]:
                del nums[index]
            else:
                index += 1
        return len(nums)       

# 第二种思路，双指针法
# 60ms 98.07
class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        i = 0
        for j in range(1, len(nums)):
            if nums[j] != nums[i]:
                i += 1
                nums[i] = nums[j]
        return i + 1