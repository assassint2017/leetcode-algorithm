// 题目要求log的时间复杂度
// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Factorial Trailing Zeroes.
// Memory Usage: 10.9 MB, less than 81.08% of C++ online submissions for Factorial Trailing Zeroes.

class Solution 
{
public:
    int trailingZeroes(int n) 
    {
        int sum = 0;
        while (n > 0)
        {
            sum += (n / 5);
            n /= 5;
        }
        return sum;
    }
};

// Runtime: 12 ms, faster than 54.92% of C++ online submissions for Factorial Trailing Zeroes.
// Memory Usage: 11 MB, less than 48.65% of C++ online submissions for Factorial Trailing Zeroes.
class Solution 
{
public:
    int trailingZeroes(int n) 
    {
        int sum = 0;
        // 注意这里为了防止溢出而使用了long
        for (long temp = 5; temp <= n; temp *= 5)
            sum += (n / temp);
        return sum;
    }
};