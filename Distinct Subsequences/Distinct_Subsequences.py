# 非递归的动态规划版本的py代码

# Runtime: 164 ms, faster than 48.91% of Python3 online submissions for Distinct Subsequences.
# Memory Usage: 12.6 MB, less than 28.98% of Python3 online submissions for Distinct Subsequences.

class Solution(object):
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        if len(t) == 0:
            return 1
        if len(s) == 0:
            return 0

        temp = [1 for i in range(len(s) + 1)]
        res = [0 for i in range(len(s) + 1)]

        for i in range(1, len(t) + 1):
            res[0] = 0
            for j in range(1, len(s) + 1):
                if s[len(s) - j] == t[len(t) - i]:
                    res[j] = res[j - 1] + temp[j - 1]
                else:
                    res[j] = res[j - 1]
            for i in range(len(s) + 1):
                temp[i] = res[i]
        
        return res[len(s)]
        