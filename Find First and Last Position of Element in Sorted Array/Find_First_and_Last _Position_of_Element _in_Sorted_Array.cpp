// 类似的问题是在一个排好序的数组中，统计给定的一个数字的出现次数
// 大概思路都是二分查找

// 这道题很关键，因为二分查找到最后只有两个数字的时候是有可能造成无限循环的

// Runtime: 8 ms, faster than 99.66% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
// Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for Find First and Last Position of Element in Sorted Array.

class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> res(2, -1);
        if (nums.empty())
            return res;

        // 第一次二分查找，这里为了减少每一次循环时的判断数量，将三种情况合并为两种
        int left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }

        if (nums[left] == target)
            res[0] = left;
        else
            return res;
        
        // 第二次二分查找        
        right = nums.size() - 1;
        while(left < right)
        {
            // 无限循环的解决方法！！！
            int mid = (left + right) / 2 + 1;
            if (nums[mid] <= target)
                left = mid;
            else
                right = mid - 1;
        }
        res[1] = right;
        return res;
    }
};