# 第一种思路，使用内置函数，简单粗暴
# 40ms 99.92%
class Solution:
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        return bin(int(a, 2) + int(b, 2))[2:]

# 第二种思路，直接按位相加
# 48ms 76.73%
class Solution:
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        res_str, carry = '', 0
        while a or b:
            str1 = (1 if a[-1] is '1' else 0) if a else 0
            str2 = (1 if b[-1] is '1' else 0) if b else 0
            temp = str1 + str2 + carry
            if temp > 1:
                carry = temp // 2
                temp %= 2
            else:
                carry = 0
            res_str += '1' if temp is 1 else '0'
            
            a = a[:-1]
            b = b[:-1]

        if carry is not 0:
            res_str += str(carry)
        return res_str[::-1]    