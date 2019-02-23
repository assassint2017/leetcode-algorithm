// 题目要求对数的时间复杂度
// 首先是线性时间复杂度的版本
// Runtime: 8 ms, faster than 99.42% of C++ online submissions for Find Peak Element.
// Memory Usage: 8.9 MB, less than 48.03% of C++ online submissions for Find Peak Element.

class Solution 
{
public:
    int findPeakElement(vector<int>& nums) 
    {
        if (nums.size() == 1 || nums[0] > nums[1])
            return 0;
        if (nums[nums.size() - 1] > nums[nums.size() - 2])
            return nums.size() - 1;
        
        int res;
        for (int i = 1; i <= nums.size() - 2; i++)
        {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
            {
                res = i;
                break;
            }
        }
        return res;
    }
};

// 思路二
// 二分法确保时间复杂度

// Runtime: 12 ms, faster than 6.14% of C++ online submissions for Find Peak Element.
// Memory Usage: 8.8 MB, less than 90.32% of C++ online submissions for Find Peak Element.

class Solution 
{
public:
    int findPeakElement(vector<int>& nums) 
    {
        int leftPtr = 0, rightPtr = nums.size() - 1;
        while (leftPtr < rightPtr)
        {
            int mid1 = (leftPtr + rightPtr) / 2;
            int mid2 = mid1 + 1;

            if (nums[mid1] < nums[mid2])
                leftPtr = mid2;
            else
                rightPtr = mid1;
        }
        return leftPtr;
    }
};