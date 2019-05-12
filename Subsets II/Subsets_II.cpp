// Runtime: 8 ms, faster than 99.12% of C++ online submissions for Subsets II.
// Memory Usage: 9.4 MB, less than 60.51% of C++ online submissions for Subsets II.

class Solution 
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> tempres;

        sort(nums.begin(), nums.end());
        helper(res, tempres, nums, 0);
        return res;
    }
private:
    void helper(vector<vector<int>>& res, vector<int>& tempres, vector<int>& nums, int beginIndex)
    {
        res.push_back(tempres);
        for (int i = beginIndex; i < nums.size(); i++)
        {
            if (i > beginIndex && nums[i] == nums[i - 1])
                continue;

            tempres.push_back(nums[i]);
            helper(res, tempres, nums, i + 1);
            tempres.pop_back();
        }
    }
};