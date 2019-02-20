# nlogn 的py代码

# Runtime: 32 ms, faster than 100.00% of Python3 online submissions for Longest Increasing Subsequence.
# Memory Usage: 12.5 MB, less than 93.78% of Python3 online submissions for Longest Increasing Subsequence.

class Solution:
    def lengthOfLIS(self, nums: 'List[int]') -> 'int':
        if len(nums) <= 1:
            return len(nums)
        
        tails = []
        tails.append(nums[0])

        for i in range(1, len(nums)):
            if nums[i] > tails[-1]:
                tails.append(nums[i])
            else:
                leftPtr, rightPtr = 0, len(tails) - 1
                while leftPtr < rightPtr:
                    midPtr = (leftPtr + rightPtr) // 2
                    if tails[midPtr] < nums[i]:
                        leftPtr = midPtr + 1
                    else:
                        rightPtr = midPtr
                tails[leftPtr] = nums[i]
        
        return len(tails)