// Runtime: 116 ms, faster than 68.68% of C++ online submissions for Find All Numbers Disappeared in an Array.
// Memory Usage: 14.9 MB, less than 86.67% of C++ online submissions for Find All Numbers Disappeared in an Array.

class Solution 
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
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
                res.push_back(index + 1);
            }
        }
        
        return res;
    }
};