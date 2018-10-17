# 36ms 100%
class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if not nums:
            return -1

        left, right = 0, len(nums) - 1
        while True:
 
            if right - left <= 1:
                if nums[right] == target:
                    return right
                elif nums[left] == target:
                    return left
                else:
                    return -1

            mid = (left + right) // 2

            if nums[left] < nums[mid]:
                if nums[left] <= target <= nums[mid]:
                    right = mid
                else:
                    left = mid + 1
            else:
                if nums[mid] <= target <= nums[right]:
                    left = mid
                else:
                    right = mid - 1