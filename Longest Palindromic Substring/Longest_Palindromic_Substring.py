# 1004ms 77.20%
# 基本思路是，对于每个字符和两个字符的中间，都可能成为一个回文子字符串的中心
# 因此，使用线性的扫描，对每个中心进行查找
class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return ''
        len_str, max_length, index = len(s), 0, 0.5
        while index < len_str - 1:
            left = int(index - 0.5)
            right = int(index) + 1
            length = 1 if int(index) == index else 0
            
            while left >= 0 and right <= len_str - 1:
                if s[left] == s[right]:
                    length += 2
                    if length > max_length:
                        max_length = length
                        max_sub_string = s[left:right + 1]
                    left -= 1;right += 1
                else:
                    break
            index += 0.5
        return s[0] if max_length is 0 else max_sub_string