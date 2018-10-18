# 60ms 75.10%
class Solution:
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        current_index = 0
        step = 0
        max_index = len(nums) - 1
        
        while current_index < max_index:        
            if current_index + nums[current_index] >= max_index:
                step += 1
                return step
            temp_list = nums[current_index + 1:current_index + 1 + nums[current_index]]
            temp_list = [num + index for index, num in enumerate(temp_list)]
    
            current_index += (temp_list.index(max(temp_list)) + 1)
            step += 1
        
        return step