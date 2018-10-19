# 40ms 73.00%
class Solution:
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        res_list = [0]
        for i in range(1, n + 1):
            res_list += [item + 2 ** (i - 1) for item in res_list[::-1]]
        return res_list