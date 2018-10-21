# 题目要求是线性的时间复杂度，并且使用常数的存储空间

# 第一种思路，不符合题目要求，因为如果创建set，那么储存空间就不是常数
# 如果直接使用列表去做索引，那么时间复杂度也不再是线性的，这时候是O(N^2)
# 36ms 99.93%
class Solution:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = set(nums)
        index = 1
        while True:
            if index in nums:
                index += 1
            else:
                return index 

# 第二种思路
# 36ms 99.93%
class Solution:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.append(0)
        n = len(nums)
        for i in range(len(nums)): 
            if nums[i] < 0 or nums[i] >= n:
                nums[i] = 0
        for i in range(len(nums)):
            nums[nums[i] % n] += n
        for i in range(1, len(nums)):
            if nums[i] < n:
                return i
        return n