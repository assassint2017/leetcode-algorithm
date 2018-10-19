# 48ms 42.54%
class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def dfs(nums, temp_list):
            for index in range(len(nums)):
                res_list.append(temp_list + [nums[index]])
                dfs(nums[index + 1:], temp_list + [nums[index]])
            
        # 这里因此res_list至少有一个[],所以提前先加好
        res_list = [[]]
        dfs(nums, [])
        return res_list