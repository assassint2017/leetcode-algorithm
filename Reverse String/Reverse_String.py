# Runtime: 184 ms, faster than 17.07% of Python3 online submissions for Reverse String.
# Memory Usage: 17.5 MB, less than 11.53% of Python3 online submissions for Reverse String.

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        leftPtr, rightPtr = 0, len(s) - 1
        while leftPtr < rightPtr:
            s[leftPtr], s[rightPtr] = s[rightPtr], s[leftPtr]
            leftPtr += 1
            rightPtr -= 1        