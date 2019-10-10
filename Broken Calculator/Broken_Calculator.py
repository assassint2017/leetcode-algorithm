# Runtime: 40 ms, faster than 27.06% of Python3 online submissions for Broken Calculator.
# Memory Usage: 14 MB, less than 50.00% of Python3 online submissions for Broken Calculator.

class Solution:
    def brokenCalc(self, start: int, end: int) -> int:
        
        if start >= end:
            return start - end
        
        if end % 2 is 0:
            return self.brokenCalc(start, end // 2) + 1
        else:
            return self.brokenCalc(start, end + 1) + 1