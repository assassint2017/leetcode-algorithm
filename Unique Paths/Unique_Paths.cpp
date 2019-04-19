// 典型的动态规划

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Unique Paths.
// Memory Usage: 8.6 MB, less than 42.42% of C++ online submissions for Unique Paths.

class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        if (m <= 0 || n <= 0)
            return 0;

        int **res = new int*[m];    
        for (int i = 0; i < n; i++)
            res[i] = new int[n]();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cout << res[i][j];
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0)
                    res[i][j] = 1;
                else
                    res[i][j] = res[i - 1][j] + res[i][j - 1];
            }
        }

        int temp = res[m - 1][n - 1];
        delete[] res;
        return temp;
    }
};