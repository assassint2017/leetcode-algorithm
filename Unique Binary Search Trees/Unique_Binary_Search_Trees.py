# 32ms 100%

class Solution:
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        res = [0 for _ in range(n + 1)]
        res[0] = res[1] = 1
        for i in range(2, n + 1):
            for j in range(i):
                res[i] += (res[j] * res[i - j - 1])
        return res[n]
