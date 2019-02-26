// Runtime: 4 ms, faster than 100.00% of C++ online submissions for House Robber II.
// Memory Usage: 9.1 MB, less than 31.74% of C++ online submissions for House Robber II.

class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return nums[0];
        else if (nums.size() == 2)
            return max(nums[0], nums[1]);
        else
        {
            int temp1 = nums[0] + helper(nums, 2, nums.size() - 2);
            int temp2 = nums[1] + helper(nums, 3, nums.size() - 1);
            int temp3 = nums[2] + helper(nums, 4, nums.size() - 1);
            
            return max(max(temp1, temp2), temp3);
        }
    }
private:
    int helper(vector<int>& nums, int start, int end)
    {
        if (start > end)
            return 0;
        
        int *res = new int[nums.size()]();

        // 边界初始化
        res[end] = nums[end];
        res[end - 1] = max(nums[end], nums[end - 1]);
        res[end - 2] = max(nums[end] + nums[end - 2], nums[end - 1]);

        for (int i = end - 3; i >= start; i--)
            res[i] = max(nums[i] + res[i + 2], nums[i + 1] + res[i + 3]);

        int finres = res[start];
        delete[] res;
        return finres;
    }
};