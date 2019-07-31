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

// 非递归的版本
// 动态规划 memo[i][j]代表（从右往左）长度为j的p能否匹配长度为i的s

class Solution 
{
public:
    bool isMatch(string s, string p) 
    {        
        vector<vector<bool>> memo(s.length() + 1, vector<bool>(p.length() + 1, false));
        memo[0][0] = true;
        
        for (int i = 0; i <= s.size(); ++i)
        {
            for (int j = 1; j <= p.size(); ++j)
            {
                bool match = i != 0 && (s[s.length() - i] == p[p.length() - j] || p[p.length() - j] == '.') ? true : false;
                if (j != 1 && p[p.length() - j + 1] == '*')
                    memo[i][j] = (j - 2 >= 0 && memo[i][j - 2]) || (match && memo[i - 1][j]);
                else
                    memo[i][j] = match && memo[i - 1][j - 1];
            }
        }
        
        return memo[s.size()][p.size()];
    }
};
