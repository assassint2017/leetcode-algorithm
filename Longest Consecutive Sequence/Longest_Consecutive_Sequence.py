# 思路一的py代码

# Runtime: 40 ms, faster than 88.35% of Python3 online submissions for Longest Consecutive Sequence.
# Memory Usage: 12.9 MB, less than 99.52% of Python3 online submissions for Longest Consecutive Sequence.

class Solution:
    def longestConsecutive(self, nums: 'List[int]') -> 'int':
        if not nums:
            return 0
        
        nums.sort()
        
        Length, maxLength = 1, 1
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1] + 1:
                Length += 1
                maxLength = max(maxLength, Length)
            elif nums[i] == nums[i - 1]:
                pass
            else:
                Length = 1
        
        return maxLength

# 思路二的py代码
# Runtime: 40 ms, faster than 88.35% of Python3 online submissions for Longest Consecutive Sequence.
# Memory Usage: 13.4 MB, less than 66.67% of Python3 online submissions for Longest Consecutive Sequence.

class Solution:
    def longestConsecutive(self, nums: 'List[int]') -> 'int':
        hashmap = dict()
        maxLength = 0

        for num in nums:
            if num not in hashmap:

                right = hashmap[num + 1] if num + 1 in hashmap else 0
                left = hashmap[num - 1] if num - 1 in hashmap else 0

                length = left + right + 1
                maxLength = max(length, maxLength)

                hashmap[num] = length
                hashmap[num - left] = length
                hashmap[num + right] = length
        
        return maxLength
        