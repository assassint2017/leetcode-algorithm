# 32ms 100%
class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix:
            return []
        m, n = len(matrix), len(matrix[0])
        i_max, i_min, j_max, j_min = m - 1, 0, n - 1, 0
        res_list = []
        while True:
            # 列从左向右
            res_list += matrix[i_min][j_min:j_max + 1]
            i_min += 1
            if len(res_list) == (m * n):
                break
            # 行从上到下
            res_list += [matrix[i][j_max] for i in range(i_min, i_max + 1, 1)]
            j_max -= 1
            if len(res_list) == (m * n):
                break
            # 列从右到左
            res_list += matrix[i_max][j_min:j_max + 1][::-1]
            i_max -= 1
            if len(res_list) == (m * n):
                break
            # 行从下到上
            res_list += [matrix[i][j_min] for i in range(i_max, i_min - 1, -1)]
            j_min += 1  
        return res_list