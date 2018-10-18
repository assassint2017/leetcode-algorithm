# 第一种思路，使用二分查找
# 64ms 68.33%
class Solution:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        left, right = 0, x
        while right - left > 1:
            mid = (left + right) // 2

            if mid ** 2 > x:
                right = mid - 1
            else:
                left = mid

        return left if right ** 2 > x else right