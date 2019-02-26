# Runtime: 40 ms, faster than 41.70% of Python3 online submissions for House Robber II.
# Memory Usage: 13.2 MB, less than 6.73% of Python3 online submissions for House Robber II.

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) is 0:
            return 0
        elif len(nums) is 1:
            return nums[0]
        elif len(nums) is 2:
            return max(nums[0], nums[1])
        else:
            return max(
                nums[0] + self.helper(nums, 2, len(nums) - 2),
                nums[1] + self.helper(nums, 3, len(nums) - 1),
                nums[2] + self.helper(nums, 4, len(nums) - 1),
            )
    def helper(self, nums, start, end):
        if start > end:
            return 0
        res = [0 for i in range(len(nums))]

        res[end] = nums[end]
        res[end - 1] = max(nums[end], nums[end - 1])
        res[end - 2] = max(nums[end] + nums[end - 2], nums[end - 1])

        for i in range(end - 3, start - 1, -1):
            res[i] = max(nums[i] + res[i + 2], nums[i + 1] + res[i + 3])

        return res[start]