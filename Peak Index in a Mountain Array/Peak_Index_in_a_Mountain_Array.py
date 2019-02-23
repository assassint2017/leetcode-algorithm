# Runtime: 32 ms, faster than 100.00% of Python3 online submissions for Peak Index in a Mountain Array.
# Memory Usage: 13.5 MB, less than 6.90% of Python3 online submissions for Peak Index in a Mountain Array.

class Solution:
    def peakIndexInMountainArray(self, A: 'List[int]') -> 'int':
        
        leftPtr, rightPtr = 0, len(A) - 1
        while leftPtr < rightPtr:
            midPtr = (leftPtr + rightPtr) // 2

            if A[midPtr - 1] < A[midPtr] < A[midPtr + 1]:
                leftPtr = midPtr + 1
            elif A[midPtr - 1] > A[midPtr] > A[midPtr + 1]:
                rightPtr = midPtr - 1
            else:
                leftPtr = midPtr
                break
        
        if A[leftPtr - 1] < A[leftPtr] > A[leftPtr + 1]:
            return leftPtr
        else:
            return rightPtr