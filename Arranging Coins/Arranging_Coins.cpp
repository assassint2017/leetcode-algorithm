// Runtime: 8 ms, faster than 56.82% of C++ online submissions for Arranging Coins.
// Memory Usage: 8.3 MB, less than 71.43% of C++ online submissions for Arranging Coins.

class Solution 
{
public:
    int arrangeCoins(int n) 
    {
        if (n < 1)
        {
            return 0;    
        }
        
        long long limit = ceil(sqrt(2.0 * n));
        
        for (long long i = limit; i >= 1; --i)
        {
            if ((1 + i) * i <= 2 * static_cast<long long>(n))
            {
                return i;
            }
        }
        
        return 1;
    }
};