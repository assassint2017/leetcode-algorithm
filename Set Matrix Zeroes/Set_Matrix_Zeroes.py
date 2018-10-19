# 128ms 31.39%
class Solution:
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        m, n = len(matrix), len(matrix[0])
        if m is 0 or n is 0:
            return

        first_row_zero = True if 0 in matrix[0] else False
        first_column_zero = True if 0 in [row[0] for row in matrix] else False

        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] is 0:
                    matrix[0][j] = matrix[i][0] = 0

        for i in range(1, m):
            for j in range(1, n):
                if matrix[0][j] is 0 or matrix[i][0] is 0:
                    matrix[i][j] = 0

        if first_row_zero is True:
            for j in range(n):
                matrix[0][j] = 0

        if first_column_zero is True:
            for i in range(m):
                matrix[i][0] = 0