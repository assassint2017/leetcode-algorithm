# 40ms 99.63%
class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        if not nums:
            return False

        left, right = 0, len(nums) - 1
        while True:
            if right - left <= 1:
                if nums[right] == target or nums[left] == target:
                    return True
                else:
                    return False

            mid = (left + right) // 2
            if nums[left] < nums[mid]:
                if nums[left] <= target <= nums[mid]:
                    right = mid
                else:
                    left = mid + 1
            elif nums[left] > nums[mid]:
                if nums[mid] <= target <= nums[right]:
                    left = mid
                else:
                    right = mid - 1
            else:
                if target == nums[mid]:
                    return True
                if len(set(nums[left:mid + 1])) is 1:
                    left = mid + 1
                else:
                    right = mid - 1