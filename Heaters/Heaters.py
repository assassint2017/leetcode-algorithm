# 思路二的py代码
# Runtime: 456 ms, faster than 22.59% of Python3 online submissions for Heaters.
# Memory Usage: 17.2 MB, less than 8.33% of Python3 online submissions for Heaters.

class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        
        heaters = sorted(heaters)

        res = -99
        for house in houses:
            leftPtr, rightPtr = 0, len(heaters) - 1

            while leftPtr < rightPtr - 1:
                mid = (leftPtr + rightPtr) // 2
                if heaters[mid] >= house:
                    rightPtr = mid
                else:
                    leftPtr = mid
            res = max(res, min(abs(heaters[rightPtr] - house), abs(heaters[leftPtr] - house)))

        return res