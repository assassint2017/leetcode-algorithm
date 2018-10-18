# 44ms 97.44%
class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        current_index, len_nums = 0, len(nums)
        if 0 not in nums:
            return True
        if nums[0] is 0:
            return False if len_nums > 1 else True
        
        while True:            
            value_list = [index + num for index, num in enumerate(nums[current_index + 1:current_index + nums[current_index] + 1])]
            max_step = value_list.index(max(value_list)) + 1
            
            if current_index + max_step >= len_nums - 1:
                return True
            
            current_index += max_step
            
            if nums[current_index] is 0:
                return False