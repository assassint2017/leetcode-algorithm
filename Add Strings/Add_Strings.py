# 基本思路，按位相加
# 60ms 67.76%
class Solution:
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        res_list, carry = [], 0
        num1, num2 = list(num1), list(num2)
        while num1 or num2:
            n1 = ord(num1.pop()) - ord('0') if num1 else 0
            n2 = ord(num2.pop()) - ord('0') if num2 else 0

            temp = n1 + n2 + carry
            res_list.append(str(temp % 10))
            carry = temp // 10

        if carry is not 0:
            res_list.append(str(carry))
        return ''.join(res_list[::-1])