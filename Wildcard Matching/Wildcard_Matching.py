# 第一种思路，基于备忘录的动态规划，和第十题类似，但是难度更大
# 在书写过程中，发现一个最大的问题就是递归的时候，需要设定好边界（递归）停止条件，否则程序就是达到最大递归深度
# 1288ms 30.78%
# 等学习了之后再回过来提高速度吧
class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        memo = {}
        def dp(i, j):
            if (i, j) not in memo:
                if j == len(p):
                    ans = i == len(s)
                elif i == len(s):
                    ans = set(p[j:]) == {'*'}
                else:
                    if p[j] == '*':
                        ans = dp(i, j + 1) or dp(i + 1, j)
                    else:
                        ans = (p[j] == s[i] or p[j] == '?') and dp(i + 1, j + 1)
                memo[(i, j)] = ans
            return memo[(i, j)]
        return dp(0, 0)
