# Runtime: 44 ms, faster than 28.30% of Python3 online submissions for Find Peak Element.
# Memory Usage: 13 MB, less than 5.29% of Python3 online submissions for Find Peak Element.

class Solution:
    def findPeakElement(self, nums: 'List[int]') -> 'int':

        leftPtr, rightPtr = 0, len(nums) - 1
        while leftPtr < rightPtr:
            mid1 = (leftPtr + rightPtr) // 2
            mid2 = mid1 + 1

            if nums[mid1] < nums[mid2]:
                leftPtr = mid2
            else:
                rightPtr = mid1
        
        return leftPtr