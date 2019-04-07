// 基本思路就是等差数据的求和 需要循环的次数可以计算一下 明显是sqrt量级的

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Consecutive Numbers Sum.
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Consecutive Numbers Sum.

class Solution 
{
public:
    int consecutiveNumbersSum(int N) 
    {
        int res = 0;
        for (int m = 1; ; m++)
        {
            int temp = 2 * N - (m - 1) * m;
            
            if (temp <= 0)
                break;
            
            if (temp % (2 * m) == 0)
                res++;
        }
        return res;
    }
};