// 典型的回溯法
// Runtime: 8 ms, faster than 98.32% of C++ online submissions for Combination Sum.
// Memory Usage: 9.4 MB, less than 80.28% of C++ online submissions for Combination Sum.

class Solution 
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        if (candidates.size() == 0 || candidates[0] > target)
            return vector<vector<int>>();
        
        vector<vector<int>> res;
        vector<int> temp;
        
        helper(candidates, res, temp, target, 0, 0);
        return res;
    }
private:
    void helper(vector<int>& candidates, vector<vector<int>>& res, vector<int>& temp, int target, int curSum, int start)
    {
        if (curSum == target)
        {
            res.push_back(temp);
            return ;
        }
        
        for (int i = start; i < candidates.size(); ++i)
        {
            if (curSum + candidates[i] > target)
                break;
            
            curSum += candidates[i];
            temp.push_back(candidates[i]);
            
            helper(candidates, res, temp, target, curSum, i);
            
            curSum -= candidates[i];
            temp.pop_back();
        }
    }
};