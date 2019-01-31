# 100ms 57.89%

class Solution:
    def maximalRectangle(self, matrix):
        
        if not matrix:
            return 0

        row = len(matrix)
        col = len(matrix[0])

        left = [-1 for i in range(col)]
        right = [col for i in range(col)]
        height = [0 for i in range(col)]

        maxArea = 0
        for i in range(row):
            curLeft, curRight = 0, col - 1
            for j in range(col):
                if matrix[i][j] == '1':
                    height[j] += 1
                    left[j] = max(left[j], curLeft)
                else:
                    height[j] = 0
                    left[j] = -1
                    curLeft = j + 1
            for j in range(col - 1, -1, - 1):
                if matrix[i][j] == '1':
                    right[j] = min(right[j], curRight)
                    maxArea = max(maxArea, (right[j] - left[j] + 1) * height[j])
                else:
                    right[j] = col
                    curRight = j - 1
        return maxArea