// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Lines To Write String.
// Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Number of Lines To Write String.

class Solution 
{
public:
    vector<int> numberOfLines(vector<int>& widths, string S) 
    {
        int res = 1;

        int cur = 0;
        for (int index = 0; index < S.length(); )    
        {
            if (cur + widths[S[index] - 'a'] > 100)
            {
                ++res;
                cur = 0;
            }
            else
            {
                cur += widths[S[index] - 'a'];
                ++index;
            }
        }

        vector<int> vec = {res, cur};
        return vec;
    }
};