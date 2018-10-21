# 40ms 93.85%
class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if len(matrix) is 0 or len(matrix[0]) is 0:
            return False
        first_column = [row[0] for row in matrix]
        # 找到第一个等于或者最后一个小于目标的索引
        start_index, end_index = 0, len(first_column) - 1
        while start_index <= end_index:
            mid_index = (start_index + end_index) // 2
            if target < first_column[mid_index]:
                end_index = mid_index - 1
            else:
                start_index = mid_index + 1
        row = matrix[end_index]
        # 第二次二分查找
        start_index, end_index = 0, len(row) - 1
        while start_index <= end_index:
            mid_index = (start_index + end_index) // 2
            if target <= row[mid_index]:
                end_index = mid_index - 1
            else:
                start_index = mid_index + 1
        if start_index < len(row) and row[start_index] == target:
            return True
        return False