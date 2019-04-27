// 很明显的位运算的题
// 这个题目使用了 (n - 1) & n 的trick
// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Power of Two.
// Memory Usage: 8.1 MB, less than 43.40% of C++ online submissions for Power of Two.
class Solution 
{
public:
    bool isPowerOfTwo(int n) 
    {
        if (n <= 0)
            return false;
        else
            return !((n - 1) & n);    
    }
};