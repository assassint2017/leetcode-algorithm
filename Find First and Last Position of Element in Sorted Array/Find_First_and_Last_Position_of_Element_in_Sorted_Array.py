# 使用两次二分查找分别对起始点和终止点进行搜索
# 和search in a 2D matrix 很相似，考察的都是二分查找的变体
# 40ms 95.13%
class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if not nums:
            return [-1, -1]
        
        # 查找第一个等于目标值的索引位置
        left, right = 0, len(nums) - 1
        while right - left > 1:
            mid = (left + right) // 2
            if nums[mid] >= target:
                right = mid
            else:
                left = mid + 1
        if nums[left] == target:
            start_index = left
        elif nums[right] == target:
            start_index = right
        else:
            return [-1, -1]
        # 查找最后一个等于目标值的索引位置
        left, right = start_index, len(nums) - 1
        while right - left > 1:
            mid = (left + right) // 2
            if nums[mid] <= target:
                left = mid
            else:
                right = mid - 1
        if nums[right] == target:
            return [start_index, right]
        elif nums[left] == target:
            return [start_index, left]