# 60ms 96.88%
class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        # 首先去掉左边的空格
        str = str.lstrip()
        if not str:
            return 0
        
        # 对第一个字符进行判断
        first_letter = str[0]
        sign = 1
        if first_letter is '+':
            str = str[1:]
        elif first_letter is '-':
            str = str[1:]
            sign = -1
        elif first_letter < '0' or first_letter > '9':
            return 0

        # 获取子字符串
        len_string = len(str)
        tail_index = 0

        while tail_index < len_string:
            if str[tail_index] >= '0' and str[tail_index] <= '9':
                tail_index += 1
            else:
                break
        sub_string = str[:tail_index]
        if not sub_string:
            return 0

        # 进行数字转换
        num = int(sub_string) * sign

        # 判断是否溢出
        if num > 2 ** 31 - 1:
            return 2 ** 31 - 1
        elif num < - 2 ** 31:
            return - 2 ** 31
        else:
            return num