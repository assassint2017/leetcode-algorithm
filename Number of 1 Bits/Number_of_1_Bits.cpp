// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Number of 1 Bits.
// Memory Usage: 8.4 MB, less than 5.28% of C++ online submissions for Number of 1 Bits.

class Solution 
{
public:
    int hammingWeight(uint32_t n) 
    {
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            if (n & 1 == 1)
                res++;
            n >>= 1;
        }
        return res;
    }
};

// 加入提前终止条件
class Solution 
{
public:
    int hammingWeight(uint32_t n) 
    {
        int res = 0;
        while (n > 0)
        {
            if (n & 1 == 1)
                res++;
            n >>= 1;
        }
        return res;
    }
};