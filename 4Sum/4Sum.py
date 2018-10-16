# 120ms 84.59%
# 首先实现一个高效的towsum查找，然后利用递归的思想来解决
# 当然也可以把写成嵌套函数的形式
class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        res_list = []
        self.findNsum(nums, 4, target, [], res_list)
        return res_list
        
    def findNsum(self, nums, N, target, temp_list, res_list):
        # 毕竟不可以求小于两个数求和，另外如果数组的长度比N还要小，当然也不行
        if N < 2 or len(nums) < N:
            return 
        # 高效的towsum查找  
        if N is 2:
            l, r = 0, len(nums) - 1
            while l < r:
                s = nums[l] + nums[r]
                if s == target:
                    res_list.append(temp_list + [nums[l], nums[r]])
                    while l < r and nums[l] == nums[l + 1]:
                        l += 1
                    while l < r and nums[r] == nums[r - 1]:
                        r -= 1
                    r -= 1;l += 1
                elif s > target:
                    r -= 1
                else:
                    l += 1
        else:
            for i in range(len(nums) - N + 1):
                # 如果重复了就跳过
                if i > 0 and nums[i] == nums[i - 1]:
                    continue
                # 如果加和不可能等于target同样跳过
                if nums[i] * N > target or nums[-1] * N < target:
                    continue
                self.findNsum(nums[i + 1:], N - 1, target - nums[i], temp_list + [nums[i]], res_list)