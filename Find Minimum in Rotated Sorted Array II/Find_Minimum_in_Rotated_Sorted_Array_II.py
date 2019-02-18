# Runtime: 36 ms, faster than 100.00% of Python3 online submissions for Find Minimum in Rotated Sorted Array II.
# Memory Usage: 12.8 MB, less than 100.00% of Python3 online submissions for Find Minimum in Rotated Sorted Array II.

class Solution:
    def findMin(self, nums: 'List[int]') -> 'int':
        return self.helper(nums, 0, len(nums) - 1)

    def helper(self, nums, leftPtr, rightPtr):
        if nums[leftPtr] < nums[rightPtr]:
            return nums[leftPtr]
        
        while rightPtr - leftPtr > 1:
            midPtr = (leftPtr + rightPtr) // 2

            if nums[leftPtr] < nums[midPtr]:
                leftPtr = midPtr
            elif nums[leftPtr] > nums[midPtr]:
                rightPtr = midPtr
            else:
                if nums[rightPtr] != nums[rightPtr]:
                    leftPtr = midPtr
                else:
                    return min(self.helper(nums, leftPtr, midPtr), self.helper(nums, midPtr + 1, rightPtr))
        
        return min(nums[leftPtr], nums[rightPtr])