# 第一种思路，使用内置小函数
# 32ms 100%
class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        return len(s.strip().split(' ')[-1])

# 第二种思路
# 36ms 92.43%
class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        last_index = '#'
        for index in range(len(s) - 1, -1, -1):
            if s[index] != ' ':
                last_index = index
                break
        if last_index == '#':
            return 0
        for index in range(last_index, -1 , -1):
            if s[index] == ' ':
                return last_index - index
        return last_index + 1