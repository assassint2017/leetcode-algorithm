# 68ms 97.90%
class Solution:
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res_list = []
        nums.sort()
        def my_permute(nums, temp_list):
            if len(nums) is 1:
                res_list.append(temp_list + nums)
            else:
                for index in range(len(nums)):
                    if index > 0 and nums[index] == nums[index - 1]:
                        continue
                    my_permute(nums[:index] + nums[index + 1:], temp_list + [nums[index]])
                    
        my_permute(nums, [])
        return res_list