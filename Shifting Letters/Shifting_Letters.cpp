// 从后向前，反向解决问题

// Runtime: 52 ms, faster than 92.07% of C++ online submissions for Shifting Letters.
// Memory Usage: 11.7 MB, less than 75.00% of C++ online submissions for Shifting Letters.

class Solution 
{
public:
    string shiftingLetters(string S, vector<int>& shifts) 
    {
        string res = S;
        
        int shift = 0;
        
        for (int index = res.length() - 1; index >= 0; --index)
        {
            shift = (shift + shifts[index]) % 26;

            int temp = res[index] - 'a';
            temp = (temp + shift) % 26;

            res[index] = (temp + 'a');
        }
        
        return res;
    }
};