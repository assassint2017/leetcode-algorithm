# 按位左移
# 52ms 99.27%
class Solution:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        # 注意判断正负号的方式!!!
        sign = (dividend < 0) is (divisor < 0)
        # 将两者都转换为正数去考虑
        dividend, divisor = abs(dividend), abs(divisor)
        res = 0
        while dividend >= divisor:
            temp, i = divisor, 1
            while dividend >= temp:
                dividend -= temp
                res += i
                i <<= 1
                temp <<= 1

        # 判断正负号
        res = res if sign is True else - res

        # 最终需要判断结果是否溢出
        if res > (2 << 30) - 1 or res < - (2 << 30):
            return (2 << 30) - 1
        else:
            return res