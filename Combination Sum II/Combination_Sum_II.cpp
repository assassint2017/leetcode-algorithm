// 典型的回溯法
// Runtime: 8 ms, faster than 86.52% of C++ online submissions for Combination Sum II.
// Memory Usage: 8.8 MB, less than 94.33% of C++ online submissions for Combination Sum II.

class Solution 
{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        // 边界条件处理
        sort(candidates.begin(), candidates.end());
        if (candidates.size() == 0 || candidates[0] > target)
            return vector<vector<int>>();
        
        vector<vector<int>> res;
        vector<int> temp;
        
        helper(res, candidates, temp, target, 0, 0);
        return res;
    }
    
private:
    void helper(vector<vector<int>>& res, vector<int>& candidates, vector<int>& temp, int target, int curSum, int start)
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
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            
            curSum += candidates[i];
            temp.push_back(candidates[i]);
            
            helper(res, candidates, temp, target, curSum, i + 1);
            
            curSum -= candidates[i];
            temp.pop_back();
        }
    }
};