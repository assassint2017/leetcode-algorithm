// 思路一，最为容易想到的线性时间复杂度的解决方案 
// Runtime: 48 ms, faster than 94.07% of C++ online submissions for Is Subsequence.
// Memory Usage: 17.1 MB, less than 100.00% of C++ online submissions for Is Subsequence.

class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        int slength = s.length(), tlength = t.length();
        if (slength == 0)
            return true;
        
        for  (int sPtr = 0, tPtr = 0; tPtr < tlength; tPtr++)
        {
            while (tPtr < tlength && s[sPtr] != t[tPtr])
                tPtr++;
            if (tPtr >= tlength)
                return false;
            if (++sPtr >= slength)
                return true;    
        }
        return false;
    }
};