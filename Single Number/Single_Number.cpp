// Runtime: 12 ms, faster than 98.02% of C++ online submissions for Single Number.
// Memory Usage: 9.8 MB, less than 27.98% of C++ online submissions for Single Number.

class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        int res = 0;
        for (auto number : nums)
            res ^= number;
        return res;
    }
};