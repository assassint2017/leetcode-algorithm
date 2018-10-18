# 第一种思路，使用数学
# 60ms 28.31%
class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return 2 * sum(set(nums)) - sum(nums)

# 第二种思路，异或，线性的时间复杂度
# 异或是满足交互律的
# 40ms 99.09%
class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        temp = 0
        for num in nums:
            temp ^= num
        return temp
