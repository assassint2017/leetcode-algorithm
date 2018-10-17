# 48ms 90.68%
class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """ 
        # 参考下边的链接，明确题目的要求
        # https://blog.csdn.net/nomasp/article/details/49913627
        
        # 算法参考下边的链接
        # https://www.cnblogs.com/grandyang/p/4428207.html
        flag = False
        
        for i in range(len(nums) - 1, 0, -1):
            if nums[i] > nums[i - 1]:
                first_decend = i - 1
                flag = True
                break
                
        if flag is False:
            nums.reverse()
            return
        
        for i in range(len(nums) - 1, 0, -1):
            if nums[i] > nums[first_decend]:
                first_greater = i
                break
                
        nums[first_decend], nums[first_greater] = nums[first_greater], nums[first_decend]
        
        for i in range(len(nums[first_decend + 1:]) // 2):
            nums[first_decend + 1 + i], nums[-i - 1] = nums[-i - 1], nums[first_decend + 1 + i]