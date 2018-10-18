# 第一种思路，使用组合计算公式
# 36ms 78.71%
class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        def c(n, m):
            def factorial(num):
                if num is 0:
                    return 1
                else:
                    return num * factorial(num - 1)
            return factorial(n) / (factorial(m) * factorial(n - m))

        res = 1
        index = 1
        
        while index * 2 <= n:
            res += c(n - index * 2 + index, index)
            index += 1
        
        return int(res)

# 第二种思路，使用动态规划，但是超时了
class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n is 1:
            return 1
        elif n is 2:
            return 2
        else:
            return self.climbStairs(n - 1) + self.climbStairs(n - 2)

# 第三种思路，使用基于备忘录的动态规划
# 32ms 99.97%
class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        memo = {}
        def dp(n):
            if n in memo:
                return memo[n]
            else:
                if n is 1:
                    ans = 1
                elif n is 2:
                    ans = 2
                else:
                    ans = dp(n - 1) + dp(n - 2)
                memo[n] = ans
                return memo[n]
        return dp(n)