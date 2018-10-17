# 非常基本的思路，滑动窗口查找
# 36ms 97.91%
class Solution:
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if not needle:
            return 0
        len_needle = len(needle)
        for index in range(len(haystack) - len_needle + 1):
            if haystack[index:index + len_needle] == needle:
                return index
        return -1