# Runtime: 236 ms, faster than 13.62% of Python3 online submissions for Delete Columns to Make Sorted.
# Memory Usage: 14.5 MB, less than 5.02% of Python3 online submissions for Delete Columns to Make Sorted.

class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        
        if not A:
            return 0
        
        res = 0
        
        for j in range(len(A[0])):
            for i in range(1, len(A)):
                if ord(A[i][j]) < ord(A[i - 1][j]):
                    res += 1
                    break
        
        return res