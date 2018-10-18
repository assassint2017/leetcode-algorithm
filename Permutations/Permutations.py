# 48ms 99.20%
class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res_list = []
        def my_permute(nums, temp_list):
            if len(nums) is 1:
                res_list.append(temp_list + nums)
            else:
                for index in range(len(nums)):
                    my_permute(nums[:index] + nums[index + 1:], temp_list + [nums[index]])
        
        my_permute(nums, [])
        return res_list