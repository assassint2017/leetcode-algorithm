# Runtime: 44 ms, faster than 95.81% of Python3 online submissions for Maximum Product Subarray.
# Memory Usage: 12.7 MB, less than 46.41% of Python3 online submissions for Maximum Product Subarray.
class Solution:
    def maxProduct(self, nums: 'List[int]') -> 'int':
        maxpod = imin = imax = nums[0]

        for i in range(1, len(nums)):
            if nums[i] < 0:
                imin, imax = imax, imin
            imax = max(nums[i], imax * nums[i])
            imin = min(nums[i], imin * nums[i])

            maxpod = max(maxpod, imax)
        return maxpod