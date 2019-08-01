class Solution 
{
public:
    int findLength(vector<int>& A, vector<int>& B) 
    {
        int res = 0;
        vector<vector<int>> memo(A.size() + 1, vector<int>(B.size() + 1, 0));
        
        for (int i = 1; i <= A.size(); ++i)
        {
            for (int j = 1; j <= B.size(); ++j)
            {
                if (A[A.size() - i] == B[B.size() - j])
                    memo[i][j] = memo[i - 1][j - 1] + 1;
                res = max(res, memo[i][j]);
            }
        }
        return res;
    }   
};