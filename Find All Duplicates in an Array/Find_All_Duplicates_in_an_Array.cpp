// Runtime: 116 ms, faster than 68.53% of C++ online submissions for Find All Duplicates in an Array.
// Memory Usage: 14.8 MB, less than 100.00% of C++ online submissions for Find All Duplicates in an Array.

class Solution 
{
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {        
        for (int index = 0; index < nums.size(); ++index)
        {
            while (nums[index] != index + 1)
            {
                if (nums[index] == nums[nums[index] - 1]) break;
                swap(nums[index], nums[nums[index] - 1]);
            }
        }
        
        vector<int> res;
        for (int index = 0; index < nums.size(); ++index)
        {
            if (nums[index] != index + 1)
            {
                res.push_back(nums[index]);
            }
        }
        
        return res;
    }
};