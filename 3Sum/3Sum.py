# 首先对数组进行排序，然后进行线性搜索
# 同样是双指针法
# 912ms 80.95%
class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        nums.sort()
        len_num = len(nums)
        
        for i in range(len_num - 2):
            if i > 0 and (nums[i] == nums[i - 1]):
                continue
                
            l, r = i + 1, len_num - 1
            while l < r:
                temp = nums[i] + nums[l] + nums[r]
                if temp > 0:
                    r -= 1
                elif temp < 0 :
                    l += 1
                else:
                    res.append([nums[i], nums[l], nums[r]])
                    while l < r and nums[r] == nums[r - 1]:
                        r -= 1
                    while l < r and nums[l] == nums[l + 1]:
                        l += 1    
                    l += 1
                    r -= 1       
        return res