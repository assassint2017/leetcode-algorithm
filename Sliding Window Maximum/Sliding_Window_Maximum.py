# Runtime: 116 ms, faster than 91.48% of Python3 online submissions for Sliding Window Maximum.
# Memory Usage: 20 MB, less than 23.66% of Python3 online submissions for Sliding Window Maximum.

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        
        res = []

        if len(nums) is 0:
            return res
        
        memo = []

        for i in range(k):
            while memo and nums[i] > nums[memo[-1]]:
                memo.pop()
            memo.append(i)
        
        for i in range(k, len(nums)):
            res.append(nums[memo[0]])

            while memo and nums[i] > nums[memo[-1]]:
                memo.pop()
            memo.append(i)

            if i - memo[0] >= k:
                memo.pop(0)
        
        res.append(nums[memo[0]])
        return res