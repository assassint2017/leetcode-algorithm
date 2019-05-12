// 使用交换首元素的策略实现高效算法
// Runtime: 12 ms, faster than 98.90% of C++ online submissions for Permutations.

// Memory Usage: 9.4 MB, less than 61.37% of C++ online submissions for Permutations.

class Solution 
{
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> tempres;

        helper(res, tempres, nums, 0);
        return res;

    } 
private:
    void helper(vector<vector<int>>& res, vector<int>& tempres, vector<int>& nums, int beginIndex)
    {
        if (tempres.size() == nums.size())
        {
            res.push_back(tempres);
            return;
        }

        for (int i = beginIndex; i < nums.size(); i++)
        {
            swap(nums[beginIndex], nums[i]);
            tempres.push_back(nums[beginIndex]);

            helper(res, tempres, nums, beginIndex + 1);

            tempres.pop_back();
            swap(nums[beginIndex], nums[i]);
        }
    }
};