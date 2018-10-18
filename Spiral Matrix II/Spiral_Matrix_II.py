# 36ms 99.37%
class Solution:
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        res_list = [[None for i in range(n)] for j in range(n)]
        num = 1
        
        i_max, i_min, j_max, j_min = n - 1, 0, n - 1, 0
        while True:
            # 列从左向右
            for j in range(j_min, j_max + 1, 1):
                res_list[i_min][j] = num
                num += 1
            i_min += 1
            if num == n ** 2 + 1:
                break
            # 行从上到下
            for i in range(i_min, i_max + 1, 1):
                res_list[i][j_max] = num
                num += 1
            j_max -= 1
            # 列从右到左
            for j in range(j_max, j_min - 1, -1):
                res_list[i_max][j] = num
                num += 1
            i_max -= 1
            if num == n ** 2 + 1:
                break
            # 行从下到上
            for i in range(i_max, i_min - 1, -1):
                res_list[i][j_min] = num
                num += 1
            j_min += 1
        return res_list