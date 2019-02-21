// 注意如何更加高效的，不使用pow函数来完成
// Runtime: 8 ms, faster than 99.60% of C++ online submissions for Excel Sheet Column Number.
// Memory Usage: 7.9 MB, less than 99.32% of C++ online submissions for Excel Sheet Column Number.

class Solution 
{
public:
    int titleToNumber(string s) 
    {
        // 讲道理如果这里不使用long而使用int回导致溢出
        long sum = 0;
        for (int i = 0; i < s.length(); i++)    
            sum = sum * 26 + s[i] - 'A' + 1;
        return sum;
    }
};