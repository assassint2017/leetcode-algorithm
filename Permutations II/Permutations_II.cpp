// 高分答案目前并不是很理解，所以直接用哈希表好了

// Runtime: 24 ms, faster than 93.68% of C++ online submissions for Permutations II.
// Memory Usage: 11.2 MB, less than 26.61% of C++ online submissions for Permutations II.

class Solution 
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
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
        
        unordered_set<int> hashSet;
        for (int i = beginIndex; i < nums.size(); i++)
        {
            if (hashSet.find(nums[i]) != hashSet.end())
                continue;
            else
                hashSet.insert(nums[i]);
            
            swap(nums[beginIndex], nums[i]);
            tempres.push_back(nums[beginIndex]);

            helper(res, tempres, nums, beginIndex + 1);

            tempres.pop_back();
            swap(nums[beginIndex], nums[i]);
        }
    }
};
