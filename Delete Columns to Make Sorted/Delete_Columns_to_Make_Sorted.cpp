// Runtime: 60 ms, faster than 68.94% of C++ online submissions for Delete Columns to Make Sorted.
// Memory Usage: 13.1 MB, less than 17.60% of C++ online submissions for Delete Columns to Make Sorted.

class Solution 
{
public:
    int minDeletionSize(vector<string>& A) 
    {
        // 边界条件处理
        if (A.size() == 0) return 0;

        int res = 0;
        
        for (int j = 0; j < A[0].size(); j++)
        {
            for (int i = 1; i < A.size(); i++)
            {
                if (A[i][j] < A[i - 1][j])
                {
                    res++;
                    break;
                }
            }    
        }
        return res;
    }
};