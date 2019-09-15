# Runtime: 416 ms, faster than 15.92% of Python3 online submissions for Sum of Square Numbers.
# Memory Usage: 13.8 MB, less than 50.00% of Python3 online submissions for Sum of Square Numbers.

import math

class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        
        if c is 0 or c is 1:
            return True
        
        leftPtr = 0
        rightPtr = int(math.sqrt(c))

        while leftPtr <= rightPtr:
            if leftPtr ** 2 + rightPtr ** 2 > c:
                rightPtr -= 1
            elif leftPtr ** 2 + rightPtr ** 2 < c:
                leftPtr += 1
            else:
                return True
        
        return False