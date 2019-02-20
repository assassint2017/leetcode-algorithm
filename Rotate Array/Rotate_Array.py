# Runtime: 48 ms, faster than 93.74% of Python3 online submissions for Rotate Array.
# Memory Usage: 12.4 MB, less than 99.73% of Python3 online submissions for Rotate Array.

class Solution:
    def rotate(self, nums: 'List[int]', k: 'int') -> 'None':
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums) is 0:
            return
        
        length = len(nums)
        k %= length

        if k is 0:
            return
        
        curlength = 0
        startindex = index = 0
        temp1 = nums[index]

        while curlength != length:

            newindex = (index + k) % length
            temp2 = nums[newindex]
            nums[newindex] = temp1

            if newindex == startindex:
                index = startindex = newindex + 1
                temp1 = nums[index]
            else:
                temp1 = temp2
                index = newindex

            curlength += 1        