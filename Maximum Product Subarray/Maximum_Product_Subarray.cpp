// 思路一 O(n2)
// Runtime: 352 ms, faster than 7.74% of C++ online submissions for Maximum Product Subarray.
// Memory Usage: 8.9 MB, less than 92.86% of C++ online submissions for Maximum Product Subarray.
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int res = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                res = max(res, 0);
                continue;
            }
                
            int curseq = 1;
            for (int j = i; j < nums.size(); j++)
            {
                curseq *= nums[j];
                res = max(res, curseq);
            }
        }
        return res;
    }
};

// 思路二
// https://leetcode.com/problems/maximum-product-subarray/discuss/48230/Possibly-simplest-solution-with-O(n)-time-complexity
// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Maximum Product Subarray.
// Memory Usage: 8.9 MB, less than 98.66% of C++ online submissions for Maximum Product Subarray.
class Solution 
{
public:
    int maxProduct(vector<int>& nums) 
    {
        int maxpod = nums[0], imax = nums[0], imin = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                swap(imin, imax);
            
            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]);

            maxpod = max(maxpod, imax);
        }
        return maxpod;
    }
};