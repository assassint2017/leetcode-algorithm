// 典型的深度优先搜索

// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Subsets.
// Memory Usage: 9 MB, less than 91.46% of C++ online submissions for Subsets.

class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> candidate;
        helper(res, nums, 0, candidate);
        return res;
    }
private:
    void helper(vector<vector<int>>& res, vector<int>& nums, int n, vector<int>& candidate)
    {
        res.push_back(candidate);
        for (int i = n; i < nums.size(); i++)
        {
            candidate.push_back(nums[i]);
            helper(res, nums, i + 1, candidate);
            candidate.pop_back();
        }
    }
};