// 典型的动态规划
// 时间复杂度为n2的版本

// Runtime: 48 ms, faster than 56.04% of C++ online submissions for Longest Increasing Subsequence.
// Memory Usage: 8.7 MB, less than 40.00% of C++ online submissions for Longest Increasing Subsequence.

class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        if (nums.size() <= 1)
            return nums.size();
        
        int *res = new int[nums.size()];
        for (int i = 0; i < nums.size(); i++)
            res[i] = 1;
        
        // res[i]代表以a[i]结尾的LIS的长度
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] > nums[j])
                    res[i] = max(res[i], res[j] + 1);
            }
        }
        
        // 遍历求取一下最大值
        int maxLength = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
            maxLength = max(maxLength, res[i]);
        delete[] res;
        return maxLength;
    }
};

// 时间复杂度为nlogn的版本
// https://leetcode.com/problems/longest-increasing-subsequence/discuss/74824/JavaPython-Binary-search-O(nlogn)-time-with-explanation

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Longest Increasing Subsequence.
// Memory Usage: 8.7 MB, less than 48.95% of C++ online submissions for Longest Increasing Subsequence.

class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        if (nums.size() <= 1)
            return nums.size();

        vector<int> tails;
        tails.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)     
        {
            if (nums[i] > tails.back())
                tails.push_back(nums[i]);
            else
            {
                // 使用二分法确定需要修改的索引
                int leftPtr = 0, rightPtr = tails.size() - 1;
                while (leftPtr < rightPtr)
                {
                    int midPtr = (leftPtr + rightPtr) / 2;
                    if (tails[midPtr] < nums[i])
                        leftPtr = midPtr + 1;
                    else
                        rightPtr = midPtr;
                }
                tails[leftPtr] = nums[i];
            }
        }
        return tails.size();
    }
};