// 动态规划
// 12ms 100%

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        if (matrix.size() == 0) return 0;

        int row = matrix.size();
        int col = matrix[0].size();

        int *left = new int[col];
        int *right = new int[col];
        int *height = new int[col];

        // 初始化
        for (int i = 0; i < col; i++)
        {
            left[i] = -1;
            right[i] = col;
            height[i] = 0;
        }

        int maxArea = 0;
        for (int i = 0; i < row; i++)
        {
            int curLeft = 0, curRight = col - 1;
            // 从左向右遍历
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == '1')
                {
                    height[j]++;
                    left[j] = left[j] > curLeft ? left[j] : curLeft;
                }
                else
                {
                    height[j] = 0;
                    left[j] = -1;
                    curLeft = j + 1;
                }
            }

            // 从右向左遍历
            for (int j = col - 1; j >= 0; j--)
            {
                if (matrix[i][j] == '1')
                {
                    right[j] = right[j] < curRight ? right[j] : curRight;
                    // 计算坐标点的面积
                    if ((right[j] - left[j] + 1) * height[j] > maxArea)
                        maxArea = (right[j] - left[j] + 1) * height[j];
                }
                else
                {
                    right[j] = col;
                    curRight = j - 1;
                }
            }
        }

        delete[] left;
        delete[] right;
        delete[] height;

        return maxArea;
    }
};