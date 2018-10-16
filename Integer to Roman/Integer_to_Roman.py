# 120ms 94.39%
class Solution:
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        string = ''
        while num > 0:
            if num >= 1000:
                string += 'M'
                num -= 1000
            elif num >= 900:
                string += 'CM'
                num -= 900
            elif num >= 500:
                string += 'D'
                num -= 500
            elif num >= 400:
                string += 'CD'
                num -= 400
            elif num >= 100:
                string += 'C'
                num -= 100
            elif num >= 90:
                string += 'XC'
                num -= 90
            elif num >= 50:
                string += 'L'
                num -= 50
            elif num >= 40:
                string += 'XL'
                num -= 40
            elif num >= 10:
                string += 'X'
                num -= 10
            elif num >= 9:
                string += 'IX'
                num -= 9
            elif num >= 5:
                string += 'V'
                num -= 5
            elif num >= 4:
                string += 'IV'
                num -= 4
            else:
                string += 'I'
                num -= 1
        # 最后拼接字符串
        return string