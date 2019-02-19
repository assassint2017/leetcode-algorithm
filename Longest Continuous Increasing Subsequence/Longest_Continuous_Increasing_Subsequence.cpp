// Runtime: 16 ms, faster than 97.37% of C++ online submissions for Longest Continuous Increasing Subsequence.
// Memory Usage: 9.6 MB, less than 100.00% of C++ online submissions for Longest Continuous Increasing Subsequence.
class Solution 
{
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        if (nums.size() == 0)
            return 0;

        int res = 1, maxres = 1;
        for (int i = 1; i < nums.size(); i++)    
        {
            if (nums[i] > nums[i - 1])
            {
                res++;
                maxres = max(maxres, res);
            }
            else
                res = 1;
        }
        return maxres;
    }
};