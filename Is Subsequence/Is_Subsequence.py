# Runtime: 148 ms, faster than 67.76% of Python3 online submissions for Is Subsequence.
# Memory Usage: 14.3 MB, less than 100.00% of Python3 online submissions for Is Subsequence.

class Solution:
    def isSubsequence(self, s: 'str', t: 'str') -> 'bool':
        slength, tlength = len(s), len(t)

        if (slength == 0):
            return True
        
        sPtr, tPtr = 0, 0

        while tPtr < tlength:
            while tPtr < tlength and s[sPtr] != t[tPtr]:
                tPtr += 1
            if tPtr >= tlength:
                return False
            sPtr += 1
            if sPtr >= slength:
                return True
            tPtr += 1
        
        return False