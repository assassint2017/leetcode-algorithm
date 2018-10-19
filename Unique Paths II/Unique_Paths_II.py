# 动态规划
# 36ms 99.37%
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        if m is 0 or n is 0 or obstacleGrid[0][0] is 1:
            return 0

        score = [[0 for j in range(n)] for i in range(m)]
        for i in range(1, m):
            if 1 in [row[0] for row in obstacleGrid[:i + 1]]:
                score[i][0] = 0
            else:
                score[i][0] = 1
        for j in range(n):
            if 1 in obstacleGrid[0][:j + 1]:
                score[0][j] = 0
            else:
                score[0][j] = 1
        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j] is 1:
                    score[i][j] = 0
                else:
                    score[i][j] = score[i-1][j] + score[i][j-1]
        return score[-1][-1]