// two pass 线性的时间辅助度 常数的空间复杂度

// Runtime: 16 ms, faster than 96.66% of C++ online submissions for Find Pivot Index.
// Memory Usage: 9.8 MB, less than 95.24% of C++ online submissions for Find Pivot Index.

class Solution 
{
public:
    int pivotIndex(vector<int>& nums) 
    {
        int rightSum = 0;
        for (auto item : nums)
            rightSum += item;
        
        int leftSum = 0;
        for (int index = 0; index < nums.size(); ++index)
        {
            rightSum -= nums[index];
            if (index > 0)
                leftSum += nums[index - 1];
            if (leftSum == rightSum)
                return index;
        }
        
        return -1;
    }
};