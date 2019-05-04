// 动态规划
// Runtime: 16 ms, faster than 57.38% of C++ online submissions for Regular Expression Matching.
// Memory Usage: 9.5 MB, less than 99.35% of C++ online submissions for Regular Expression Matching.

class Solution 
{
public:
    bool isMatch(string s, string p) 
    {
        this->str = s;
        this->patten = p;

        for (int i = 0; i <= str.length(); i++)
        {
            vector<char> vec(patten.length() + 1, 'U');
            memo.push_back(vec);
        }

        return (dp(0, 0) == 'T');
    }
private:
    vector<vector<char>> memo;
    string str, patten;

    char dp(int i, int j)
    {
        if (memo[i][j] == 'U')
        {
            bool ans;
            if (j == patten.length())
                ans = i == str.length();
            else
            {
                bool first_match = i < str.length() && (str[i] == patten[j] || patten[j] == '.') ? true : false;
                if (j + 1 < patten.length() && patten[j + 1] == '*')
                    ans = (dp(i, j + 2) == 'T') || (first_match && (dp(i + 1, j) == 'T'));
                else
                    ans = first_match && (dp(i + 1, j + 1) == 'T');
            }
            memo[i][j] = ans ? 'T' : 'F';
        }   
        return memo[i][j];
    }
};