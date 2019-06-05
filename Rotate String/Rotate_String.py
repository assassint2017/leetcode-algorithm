# Runtime: 28 ms, faster than 98.79% of Python3 online submissions for Rotate String.
# Memory Usage: 13.3 MB, less than 21.17% of Python3 online submissions for Rotate String.

class Solution:
    def rotateString(self, A: str, B: str) -> bool:
        
        if len(A) != len(B):
            return False
        if len(A) is 0 and len(B) is 0:
            return True
        
        for index in range(len(A)):
            if A[index:] + A[:index] == B:
                return True
        
        return False