// Runtime: 48 ms, faster than 62.52% of C++ online submissions for First Unique Character in a String.
// Memory Usage: 12.8 MB, less than 90.63% of C++ online submissions for First Unique Character in a String.

class Solution 
{
public:
    int firstUniqChar(string s) 
    {
        vector<bool> repeat(26, false);
        vector<int> memo(26, -1);
        
        for (int i = 0; i < s.length(); ++i)
        {
            if (memo[s[i] - 'a'] != -1)
            {
                repeat[s[i] - 'a'] = true;
            }
            
            memo[s[i] - 'a'] = i;
        }
        
        int res = -1;
        for (int i = 0; i < 26; ++i)
        {
            if (repeat[i] == false && memo[i] != -1)
            {
                if (res < 0)
                {
                    res = memo[i];
                }
                else
                {
                    res = min(res, memo[i]);
                }
            }
        }
        
        return res;
    }
};