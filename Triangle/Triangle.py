# 40ms 99.88%
class Solution:
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        res_list = triangle[0]
        for row in triangle[1:]:
            temp_list = row[:]
            temp_list[0] += res_list[0];temp_list[-1] += res_list[-1]
            for index in range(1, len(temp_list) - 1):
                temp_list[index] += min(res_list[index], res_list[index - 1])
            res_list = temp_list
        return min(res_list)