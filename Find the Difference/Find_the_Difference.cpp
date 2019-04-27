// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Find the Difference.
// Memory Usage: 9.1 MB, less than 93.39% of C++ online submissions for Find the Difference.

class Solution 
{
public:
    char findTheDifference(string s, string t) 
    {
        vector<int> vec(26, 0);
        int i;
        for (i = 0; i < s.length(); i++)
            vec[s[i] - 'a']++;
        for (i = 0; i < t.length(); i++)
            if (--vec[t[i] - 'a'] == -1)
                break;
        return t[i];
    }
};