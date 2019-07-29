// 动态规划

// Runtime: 16 ms, faster than 97.02% of C++ online submissions for Maximal Square.
// Memory Usage: 10.6 MB, less than 86.19% of C++ online submissions for Maximal Square.

class Solution 
{
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        // 边界条件处理
        int rows = matrix.size();
        if (rows == 0) return 0;

        int cols = matrix[0].size();
        if (cols == 0) return 0;

        int maxArea = 0;
        vector<int> left(cols, -1);
        vector<int> right(cols, cols);
        vector<int> height(cols, 0);

        for (int i = 0; i < rows; ++i)
        {
            int curLeft = 0, curRight = cols - 1;

            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    left[j] = max(left[j], curLeft);
                    ++height[j];
                }
                else
                {
                    height[j] = 0;
                    curLeft = j + 1;
                    left[j] = -1;
                }
            }

            for (int j = cols - 1; j >= 0; --j)
            {
                if (matrix[i][j] == '1')
                {
                    right[j] = min(right[j], curRight);

                    int h = height[j];
                    int w = right[j] - left[j] + 1;
                    maxArea = max(maxArea, min(w, h) * min(w, h));
                }
                else
                {
                    curRight = j - 1;
                    right[j] = cols;
                }
            }   
        }
        return maxArea;
    }
};