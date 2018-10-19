# 第一种思路，非常的简单粗暴
# 52ms 91.74%
class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        index = 2
        while index <= len(nums) - 1:
            if nums[index] == nums[index - 1] and nums[index] ==  nums[index - 2]:
                del nums[index]     
            else:
                index += 1
        return len(nums)

# 第二种思路
# 48ms 99.79%
class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        index = 0
        for num in nums:
            if index < 2 or num > nums[i - 2]:
                nums[i] = num
                i += 1
        return index