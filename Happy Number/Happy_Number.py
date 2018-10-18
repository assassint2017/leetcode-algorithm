# 第一种思路，简单粗暴，直接去模拟循环
# 48ms 86.79%
class Solution:
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        res, numlist = 0, set()
        while res != 1:
            n = list(str(n))
            res = sum([int(item) ** 2 for item in n])
            if res in numlist:
                return False
            numlist.add(res)
            n = res
        return True