// 典型的回溯法
// 下面的这种暴力写法直接超时了

class Solution 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        int res = 0;
        int curSum = 0;

        genSequence(nums, target, curSum, res);
        return res;
    }
private:
    void genSequence(const vector<int>& nums, const int& target, int& curSum, int& res)
    {
        if (curSum >= target)
        {
            if (curSum == target) 
                ++res;
            return ;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            curSum += nums[i];
            genSequence(nums, target, curSum, res);
            curSum -= nums[i];
        }
    }
};

// 转换为自底向上的动态规划来处理
// Runtime: 4 ms, faster than 67.65% of C++ online submissions for Combination Sum IV.
// Memory Usage: 8.6 MB, less than 96.67% of C++ online submissions for Combination Sum IV.
class Solution 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        // 这里如果使用int就会溢出，long同样会溢出，换成无符号就没问题，这好奇怪呀
        // 这里应该是确实结果太大的情况，答案就自动求余数了
        vector<unsigned int> memo(target + 1, 0);
        memo[0] = 1;
        for (int i = 1; i <= target; ++i)
        {
            for (auto item : nums)
            {
                if (i - item >= 0)
                    memo[i] += memo[i - item];
            }
        }

        return memo[target];
    }
};