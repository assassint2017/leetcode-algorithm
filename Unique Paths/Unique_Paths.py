# 第一种思路，使用组合计算公式
# 36ms 96.05%
class Solution:
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        def factorial(num):
            if num is 0:
                return 1
            else:
                return num * factorial(num - 1)
        
        def combination(m, n):
            return factorial(n) // factorial(m) // factorial(n - m)
        
        return combination(m - 1, m - 1 + n - 1)