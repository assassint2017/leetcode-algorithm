# 88ms 88.14%

class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        temp_list = []  # 存储子字符串
        max_length, length = 0, 0  # length跟踪子字符串的长度

        for letter in s:
            if letter not in temp_list:
                length += 1
                if length > max_length:
                    max_length = length
            else:
                # 这里由于后边的字符的最大不重复子字符串不可能超过第一个
                # 所以要从第一个已经的不重复的字符开始计算
                temp_list = temp_list[temp_list.index(letter) + 1:]
                length = len(temp_list) + 1
            temp_list.append(letter)
        return max_length
