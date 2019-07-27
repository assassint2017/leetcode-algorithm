// 典型的回溯法

// Runtime: 84 ms, faster than 66.79% of C++ online submissions for Combinations.
// Memory Usage: 11.8 MB, less than 66.84% of C++ online submissions for Combinations.

class Solution 
{
public:
    vector<vector<int>> combine(int n, int k) 
    {
        // 边界条件处理
        if (k <= 0 || n <= 0 || k > n)
            return vector<vector<int>>();
        
        vector<int> candidate(n, 0);
        for (int i = 0; i < n; ++i)
            candidate[i] = i + 1;
        
        vector<vector<int>> res;
        vector<int> temp;
        
        helper(res, candidate, temp, 0, k);
        return res;
    }
private:
    void helper(vector<vector<int>>& res, vector<int>& candidate, vector<int>& temp, int start, int k)
    {
        if (temp.size() == k)
        {
            res.push_back(temp);
            return ;
        }
        for (int i = start; i < candidate.size(); ++i)
        {
            temp.push_back(candidate[i]);
            helper(res, candidate, temp, i + 1, k);
            temp.pop_back();
        }
    }
};