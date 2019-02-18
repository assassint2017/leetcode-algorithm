// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Find Minimum in Rotated Sorted Array II.
// Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Find Minimum in Rotated Sorted Array II.

class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        return helper(nums, 0, nums.size() - 1);
    }
private:
    int helper(vector<int> &nums, int leftPtr, int rightPtr)
    {
        // 如果数组一定没有发生翻转的话就直接返回第一个作为最小值就行了
        if (nums[leftPtr] < nums[rightPtr])
            return nums[leftPtr];

        while (rightPtr - leftPtr > 1)
        {
            int midPtr = (leftPtr + rightPtr) / 2;
            
            if (nums[leftPtr] < nums[midPtr])
                leftPtr = midPtr;
            else if (nums[leftPtr] > nums[midPtr])
                rightPtr = midPtr;
            else
            {
                if (nums[rightPtr] != nums[leftPtr])
                    leftPtr = midPtr;
                // 这个时候无法确定到底是哪种情况，只好去递归
                else
                    return min(helper(nums, leftPtr, midPtr), helper(nums, midPtr + 1, rightPtr));
            }
        }
        return min(nums[leftPtr], nums[rightPtr]);
    }
};