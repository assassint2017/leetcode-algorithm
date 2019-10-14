// 剑指offer上的题目
// Runtime: 60 ms, faster than 94.48% of C++ online submissions for Search a 2D Matrix II.
// Memory Usage: 12.8 MB, less than 91.11% of C++ online submissions for Search a 2D Matrix II.

class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row = matrix.size();
        if (row == 0) return false;

        int col = matrix[0].size();
        if (col == 0) return false;

        int rowIndex = 0, colIndex = col - 1;

        while (colIndex >= 0 && rowIndex < row)
        {
            if (matrix[rowIndex][colIndex] > target)
            {
                --colIndex;
            }
            else if (matrix[rowIndex][colIndex] < target)
            {
                ++rowIndex;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};