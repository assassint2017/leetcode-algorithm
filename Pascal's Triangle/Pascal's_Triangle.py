# 36ms 91.14%
class Solution:
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        res_list = []
        if numRows is not 0:
            res_list.append([1])
        for row in range(1, numRows):
            temp_list = [1]
            for column in range(len(res_list[row - 1]) - 1):
                temp_list.append(res_list[row-1][column] + res_list[row-1][column+1])
            temp_list.append(1)
            res_list.append(temp_list)
        return res_list
