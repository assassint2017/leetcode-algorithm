# 此问题的解决思路和3Sum的思路基本一致
# 88ms 94.42%
class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        len_nums = len(nums)
        nums.sort()
        res = float('inf')
        
        for i in range(len_nums - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            l, r = i + 1, len_nums - 1
            while l < r:
                temp = nums[i] + nums[l] + nums[r]
                if temp > target:
                    if temp - target < abs(res - target):
                        res = temp    
                    while l < r and nums[r] == nums[r - 1]:
                        r -= 1
                    r -= 1
                elif temp < target:
                    if target - temp < abs(res - target):
                        res = temp
                    while l < r and nums[l] == nums[l + 1]:
                        l += 1
                    l += 1
                else:
                    return target
        return res     