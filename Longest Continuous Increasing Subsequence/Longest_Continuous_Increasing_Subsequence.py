# Runtime: 40 ms, faster than 99.42% of Python3 online submissions for Longest Continuous Increasing Subsequence.
# Memory Usage: 13.4 MB, less than 100.00% of Python3 online submissions for Longest Continuous Increasing Subsequence.

class Solution:
    def findLengthOfLCIS(self, nums: 'List[int]') -> 'int':
        if not nums:
            return 0
        res, maxres = 1, 1
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                res += 1
                maxres = max(maxres, res)
            else:
                res = 1
        return maxres