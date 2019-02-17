// 线性的时间复杂度对于这道题目来说就太慢了
class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        int minValue = INT_MAX;
        
        for (auto num : nums)
        {
            if (num < minValue)
                minValue = num;
        }
        return minValue;
    }
};

// 第二种思路 使用二分查找来搜索拐点的位置
// Runtime: 8 ms, faster than 98.48% of C++ online submissions for Find Minimum in Rotated Sorted Array.
// Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for Find Minimum in Rotated Sorted Array.
class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        int leftPtr = 0, rightPtr = nums.size() - 1;
        
        // 如果没有发生翻转，则最小值就是数组的第一个值
        if (nums[leftPtr] < nums[rightPtr])
            return nums[0];

        while (rightPtr - leftPtr > 1)
        {
            int midPtr = (leftPtr + rightPtr) / 2;

            // 数组的左半部分都是升序
            if (nums[leftPtr] < nums[midPtr])
                leftPtr = midPtr;

            // 数组的左半部分发生了翻转
            else
                rightPtr = midPtr;
        }   
        return min(nums[leftPtr], nums[rightPtr]);
    }
};