// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fibonacci Number.
// Memory Usage: 8.3 MB, less than 43.29% of C++ online submissions for Fibonacci Number.

class Solution 
{
public:
    int fib(int n) 
    {
        if (n <= 1) return n;

        int res, lres = 1, llres = 0;
        for (int i = 2; i <= n; ++i)
        {
            res = lres + llres;
            llres = lres;
            lres = res;
        }
        return res;     
    }
};