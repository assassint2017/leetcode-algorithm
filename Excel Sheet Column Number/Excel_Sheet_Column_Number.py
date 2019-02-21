# Runtime: 52 ms, faster than 99.35% of Python3 online submissions for Excel Sheet Column Number.
# Memory Usage: 12.5 MB, less than 85.71% of Python3 online submissions for Excel Sheet Column Number.

class Solution:
    def titleToNumber(self, s: 'str') -> 'int':
        sum = 0
        for i in range(len(s)):
            sum = sum * 26 + ord(s[i]) - 64
        return sum