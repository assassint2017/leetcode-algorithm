// 简单递归的动态规划
// 54 / 63 test cases passed. 超时了

class Solution 
{
public:
    int numDistinct(string s, string t) 
    {
        if (t.length() == 0)
            return 1;
        if (s.length() == 0)
            return 0;

        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == t[0])
            {
                string news(s, i + 1, s.length() - i - 1);
                string newt(t, 1, t.length() - 1);
                sum += numDistinct(news, newt);
            }   
        }
        return sum;
    }
};

// 非递归版本的动态规划

// Runtime: 12 ms, faster than 63.16% of C++ online submissions for Distinct Subsequences.
// Memory Usage: 9.1 MB, less than 0.88% of C++ online submissions for Distinct Subsequences.

class Solution 
{
public:
    int numDistinct(string s, string t) 
    {
        if (t.length() == 0) return 1;
        if (s.length() == 0) return 0;

        long *temp = new long[s.length() + 1], *res = new long[s.length() + 1];
        for (int i = 0; i <= s.length(); i++)    
            temp[i] = 1;

        for (int i = 1; i <= t.length(); i++)
        {
            res[0] = 0;
            for (int j = 1; j <= s.length(); j++)
            {
                if (s[s.length() - j] == t[t.length() - i])
                    res[j] = res[j - 1] + temp[j - 1];
                else
                    res[j] = res[j - 1];
            }
            
            for (int i = 0; i <= s.length(); i++)
                temp[i] = res[i];
        }

        int sum = res[s.length()];

        delete[] res;
        delete[] temp;

        return sum;
    }
};