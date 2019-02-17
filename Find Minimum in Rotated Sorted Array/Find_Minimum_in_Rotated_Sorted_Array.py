# Runtime: 36 ms, faster than 99.42% of Python3 online submissions for Find Minimum in Rotated Sorted Array.
# Memory Usage: 12.8 MB, less than 100.00% of Python3 online submissions for Find Minimum in Rotated Sorted Array.

class Solution:
    def findMin(self, nums: 'List[int]') -> 'int':
        leftPtr, rightPtr = 0, len(nums) - 1
        if (nums[leftPtr] < nums[rightPtr]):
            return nums[0]
        
        while rightPtr - leftPtr > 1:
            midPtr = (leftPtr + rightPtr) // 2

            if nums[leftPtr] < nums[midPtr]:
                leftPtr = midPtr
            else:
                rightPtr = midPtr
        
        return min(nums[leftPtr], nums[rightPtr])