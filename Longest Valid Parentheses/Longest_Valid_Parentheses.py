# 52ms 98.60%
class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = [-1]
        max_length = 0
        
        for index in range(len(s)):
            if s[index] is '(':
                stack.append(index)
            else:
                stack.pop()
                if not stack:
                    stack.append(index)
                else:
                    length = index - stack[-1]
                    if length > max_length:
                        max_length = length
        return max_length