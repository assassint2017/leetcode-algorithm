# 84ms 91.73%
class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        # 创建分配对象
        string_list = ['' for _ in range(numRows)]
        iter_list = list(range(numRows)) + list(range(numRows - 2, 0, -1))
        len_iter_list = len(iter_list)

        # 开始分配字符
        for index in range(len(s)):
            string_list[iter_list[index - index // len_iter_list * len_iter_list]] += s[index]

        # 完成分配之后,拼接字符串
        return ''.join(string_list)