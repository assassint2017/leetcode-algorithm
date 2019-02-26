// 思路一 简单的回溯超时了
// 59 / 69 test cases passed.
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        return helper(nums, 0);
    }
private:
    int helper(vector<int>& nums, int start)
    {
        if (start >= nums.size())
            return 0;
        else if (start == nums.size() - 1)
            return nums[start];
        else
            return max(nums[start] + helper(nums, start + 2), nums[start + 1] + helper(nums, start + 3));
    }
};

// 思路二
// 自底向上的动态规划
// Runtime: 4 ms, faster than 100.00% of C++ online submissions for House Robber.
// Memory Usage: 9.1 MB, less than 11.45% of C++ online submissions for House Robber.
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        if (nums.size() == 0)
            return 0;

        int *res = new int[nums.size()];

        // 边界初始化
        res[nums.size() - 1] = nums[nums.size() - 1];
        if (nums.size() >= 2)
            res[nums.size() - 2] = max(nums[nums.size() - 1], nums[nums.size() - 2]);
        if (nums.size() >= 3)
            res[nums.size() - 3] = max(nums[nums.size() - 1] + nums[nums.size() - 3], nums[nums.size() - 2]);

        for (int i = nums.size() - 4; i >= 0; i--)
            res[i] = max(nums[i] + res[i + 2], nums[i + 1] + res[i + 3]);

        int finres = res[0];
        delete[] res;
        return finres;
    }
};