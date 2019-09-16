// 剑指上的题目
// Runtime: 4 ms, faster than 48.35% of C++ online submissions for Number of Digit One.
// Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Number of Digit One.

class Solution 
{
public:
    int countDigitOne(int n) 
    {
        if (n <= 0)
            return 0;
        
        // 同样需要注意数据溢出的问题
        long long base = 10;
        long long count = 0;
        while (n / base > 0)
            base *= 10, count++;
        base /= 10;
        
        long long high = n / base;
        long long res = 0;
        
        if (high == 1)
            res += n - high * base + 1;
        else
            res += base;
        
        res += high * count * (base / 10);
        
        return res + countDigitOne(n - high * base);
    }
};