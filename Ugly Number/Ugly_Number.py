# Runtime: 32 ms, faster than 98.44% of Python3 online submissions for Ugly Number.
# Memory Usage: 13 MB, less than 87.74% of Python3 online submissions for Ugly Number.

class Solution:
    def isUgly(self, num: int) -> bool:
        if num is 1:
            return True
        if num <= 0:
            return False
        
        if num % 2 is 0 and self.isUgly(num // 2):
            return True
        elif num % 3 is 0 and self.isUgly(num // 3):
            return True
        elif num % 5 is 0 and self.isUgly(num // 5):
            return True
        else:
            return False