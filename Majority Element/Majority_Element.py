# Runtime: 52 ms, faster than 73.65% of Python3 online submissions for Majority Element.
# Memory Usage: 13.5 MB, less than 100.00% of Python3 online submissions for Majority Element.

class Solution:
    def majorityElement(self, nums: 'List[int]') -> 'int':
        count = 0
        res = None

        for num in nums:
            if count is 0:
                res = num
            if res == num:
                count += 1
            else:
                count -= 1
        return res