# Runtime: 332 ms, faster than 40.26% of Python3 online submissions for Daily Temperatures.
# Memory Usage: 16.6 MB, less than 67.99% of Python3 online submissions for Daily Temperatures.

class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        
        res = [0 for i in range(len(T))]

        memo = []

        for index in range(len(T) - 1, -1, -1):
            while memo and T[index] >= memo[-1][0]
                memo.pop()

            if not memo:
                res[index] = memo[-1][1] - index

            memo.append((T[index], index))

        return res