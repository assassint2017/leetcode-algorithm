# 第一种思路，使用函数转换字符串
# 48ms 82.72%
class Solution:
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        def myint(strs):
            res = 0
            for letter in strs:
                res *= 10
                res += ord(letter) - ord('0')
            return res

        def mystr(nums):
            if nums == 0:
                return '0'
            strs = ''
            while nums is not 0:
                strs += chr(nums % 10 + 48)
                nums //= 10
            return strs[::-1]

        return mystr(myint(num1) * myint(num2))