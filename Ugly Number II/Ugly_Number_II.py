# Runtime: 212 ms, faster than 34.39% of Python3 online submissions for Ugly Number II.
# Memory Usage: 13.1 MB, less than 77.29% of Python3 online submissions for Ugly Number II.

class Solution:
    def nthUglyNumber(self, n: int) -> int:
        
        if n <= 0:
            return 0
        
        mutilply2 = 0
        mutilply3 = 0  
        mutilply5 = 0

        res = [1 for i in range(n)]    

        for index in range(1, n):
            res[index] = min(min(res[mutilply2] * 2, res[mutilply3] * 3), res[mutilply5] * 5)

            while res[mutilply2] * 2 <= res[index]:
                mutilply2 += 1
            while res[mutilply3] * 3 <= res[index]:
                mutilply3 += 1
            while res[mutilply5] * 5 <= res[index]:
                mutilply5 += 1
        
        return res[-1]