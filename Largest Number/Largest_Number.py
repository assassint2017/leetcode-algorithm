# Runtime: 36 ms, faster than 100.00% of Python3 online submissions for Largest Number.
# Memory Usage: 12.5 MB, less than 53.95% of Python3 online submissions for Largest Number.

import functools

def comp(num1, num2):

    num1num2 = num1 + num2
    num2num1 = num2 + num1

    if num1num2 > num2num1:
        return -1
    elif num1num2 < num2num1:
        return 1
    else:
        return 0
    
class Solution:
    def largestNumber(self, nums: 'List[int]') -> 'str':
        
        if len(nums) is 0:
            return ''
        
        vec = [str(num) for num in nums]
        
        # 这里注意一下自定义排序函数是如何书写的
        vec = sorted(vec, key=functools.cmp_to_key(comp))
        return '0' if vec[0] == '0' else ''.join(vec)
