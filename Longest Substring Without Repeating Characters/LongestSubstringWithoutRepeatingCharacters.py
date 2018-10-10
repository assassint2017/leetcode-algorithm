# 88ms 88.14%

class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        temp_list = []
        max_length, length = 0, 0

        for letter in s:
            if letter not in temp_list:
                length += 1
                if length > max_length:
                    max_length = length
            else:
                temp_list = temp_list[temp_list.index(letter) + 1:]
                length = len(temp_list) + 1
            temp_list.append(letter)
        return max_length
