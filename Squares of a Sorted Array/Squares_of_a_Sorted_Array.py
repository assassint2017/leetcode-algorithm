# Runtime: 208 ms, faster than 16.33% of Python3 online submissions for Squares of a Sorted Array.
# Memory Usage: 15 MB, less than 79.05% of Python3 online submissions for Squares of a Sorted Array.

class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        leftPtr = 0

        while leftPtr < len(A) and A[leftPtr] < 0:
            leftPtr += 1
        
        rightPtr = leftPtr
        leftPtr -= 1

        res = []

        while leftPtr >= 0 and rightPtr < len(A):
            left = A[leftPtr] ** 2
            right = A[rightPtr] ** 2

            if left <= right:
                res.append(left)
                leftPtr -= 1
            else:
                res.append(right)
                rightPtr += 1
        
        while leftPtr >= 0:
            res.append(A[leftPtr] ** 2)
            leftPtr -= 1
        while rightPtr < len(A):
            res.append(A[rightPtr] ** 2)
            rightPtr += 1
        
        return res
