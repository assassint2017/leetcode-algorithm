# 44ms 99.26%
class Solution:
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res_list = [[]]
        nums.sort()
        def dfs(nums, temp_list):
            for i in range(len(nums)):
                if i > 0 and nums[i] == nums[i - 1]:
                    continue
                res_list.append(temp_list + [nums[i]])
                dfs(nums[i + 1:], temp_list + [nums[i]])
        dfs(nums, [])
        return res_list