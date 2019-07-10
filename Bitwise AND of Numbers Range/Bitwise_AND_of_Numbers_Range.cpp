// 典型的位运算的题目 解题思路很巧妙
// 思路一，比较低效

// Runtime: 8 ms, faster than 95.68% of C++ online submissions for Bitwise AND of Numbers Range.
// Memory Usage: 8.6 MB, less than 5.45% of C++ online submissions for Bitwise AND of Numbers Range.

class Solution 
{
public:
    int rangeBitwiseAnd(int m, int n) 
    {
        vector<bool> memo(31, false);

        for (int i = 0; i < 31; i++)
        {
            if (m == n && m & 1 == 1)
                memo[i] = true;

            m >>= 1;
            n >>= 1;

            if (m == 0 && n == 0)
                break;
        }

        // 计算最终的结果
        int res = 0;
        for (int i = 30; i >= 0; i--)
        {
            res <<= 1;
            if (memo[i])
                res++;
        }

        return res;
    }
};

// 思路二 相对高效

// Runtime: 8 ms, faster than 95.68% of C++ online submissions for Bitwise AND of Numbers Range.
// Memory Usage: 8 MB, less than 89.81% of C++ online submissions for Bitwise AND of Numbers Range.

class Solution 
{
public:
    int rangeBitwiseAnd(int m, int n) 
    {
        if (m == 0 || n == 0)
            return 0;

        int factor = 0;
        while (m != n)    
        {
            m >>= 1;
            n >>= 1;
            factor++;
        }

        return m << factor;
    }
};