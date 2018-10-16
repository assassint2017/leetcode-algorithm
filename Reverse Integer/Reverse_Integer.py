# 第一种思路，利用python自带的一些实用小函数
# 56ms 86.75%
class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: inta
        """
        # 可以用下面的方式求取符号项
        # sign = [1,-1][x < 0]

        string = str(abs(x))[::-1]
        res = int(string) if x > 0 else int(string) * -1
        return 0 if res > 2 ** 31 - 1 or res < - 2 ** 31 else res

# 第二种思路，利用位去计算
# 52ms 99.49%
class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sign = [-1, 1][x > 0]
        x *= sign
        res = 0
        while x >= 10:
            res *= 10
            res += x % 10
            x //= 10
        res *= 10
        res += x
        res *= sign
        return 0 if res > 2 ** 31 - 1 or res < - 2 ** 31 else res