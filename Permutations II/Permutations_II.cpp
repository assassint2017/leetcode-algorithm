// Runtime: 28 ms, faster than 59.59% of C++ online submissions for Permutations II.
// Memory Usage: 9.8 MB, less than 90.64% of C++ online submissions for Permutations II.

class Solution 
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> tempres;
        vector<bool> visited(nums.size(), false);
        
        sort(nums.begin(), nums.end());
        helper(res, tempres, nums, visited);
        return res;

    } 
private:
    void helper(vector<vector<int>>& res, vector<int>& tempres, vector<int>& nums, vector<bool>& visited)
    {
        if (tempres.size() == nums.size())
        {
            res.push_back(tempres);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i])
                continue;
            if (i > 0 && visited[i - 1] && nums[i - 1] == nums[i])
                continue;

            tempres.push_back(nums[i]);
            visited[i] = true;
            
            helper(res, tempres, nums, visited);
            
            tempres.pop_back();
            visited[i] = false;
        }
    }
};