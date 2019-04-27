// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Reverse Bits.
// Memory Usage: 8.3 MB, less than 5.36% of C++ online submissions for Reverse Bits.

class Solution 
{
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t res = 0, mask = 1;
        for (int i = 0; i < 32; i++)
        {
            res <<= 1;
            if (n & mask)
                res += 1;
            mask <<= 1;
        }
        return res;
    }
};