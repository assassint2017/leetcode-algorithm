# 36ms 92.91%
class Solution:
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if rowIndex is 0:
            return [1]
        else:
            temp_list = self.getRow(rowIndex - 1)
            return [1] + [temp_list[index] + temp_list[index + 1] for index in range(len(temp_list) - 1)] + [1]
