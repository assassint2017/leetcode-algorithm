// 附上大佬的解题思路，确实是太秀了
// https://leetcode.com/problems/unique-substrings-in-wraparound-string/discuss/95439/Concise-Java-solution-using-DP

// Runtime: 8 ms, faster than 91.38% of C++ online submissions for Unique Substrings in Wraparound String.
// Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for Unique Substrings in Wraparound String.

class Solution 
{
public:
    int findSubstringInWraproundString(string p) 
    {
        vector<int> memo(26, 0);
        
        int curLength = 1;
        for (int i = 0; i < p.length(); ++i)
        {
            if (i > 0 && p[i] - 'a' == (p[i - 1] - 'a' + 1) % 26)
            {
                ++curLength;
            }
            else
            {
                curLength = 1;
            }
            memo[p[i] - 'a'] = max(memo[p[i] - 'a'], curLength);
        }
        
        int res = 0;
        for (auto item : memo)
        {
            res += item;
        }
        return res;
    }
};