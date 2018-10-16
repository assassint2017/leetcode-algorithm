# 44ms 47.89%
class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        mapping = {')':'(', ']':'[', '}':'{'}
        stack = []
        for letter in s:
            if letter in mapping:
                top_letter = stack.pop() if stack else '$'
                if top_letter is not mapping[letter]:
                    return False
            else:
                stack.append(letter)
        return not stack