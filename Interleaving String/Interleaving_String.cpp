// 使用回溯的方法
// 99 / 101 test cases passed. 内存超了

class Solution 
{
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        if (s1.length() + s2.length() != s3.length())
            return false;
        if (s1.length() == 0)
        {
            if (s2 == s3)
                return true;
            else
                return false;
        }
        if (s2.length() == 0)
        {
            if (s1 == s3)
                return true;
            else
                return false;
        }

        int s1Ptr = 0, s2Ptr = 0, s3Ptr = 0;
        
        while (s3Ptr < s3.length())
        {
           if (s1Ptr < s1.length() && s2Ptr < s2.length() && s1[s1Ptr] == s3[s3Ptr] && s2[s2Ptr] == s3[s3Ptr])
            {
                return
                isInterleave(s1.substr(s1Ptr + 1), s2.substr(s2Ptr), s3.substr(s3Ptr + 1)) ||
                isInterleave(s1.substr(s1Ptr), s2.substr(s2Ptr + 1), s3.substr(s3Ptr + 1));
            }
            else if (s1Ptr < s1.length() && s1[s1Ptr] == s3[s3Ptr])
            {
                s1Ptr++;
                s3Ptr++;
            }
            else if (s2Ptr < s2.length() && s2[s2Ptr] == s3[s3Ptr])
            {
                s2Ptr++;
                s3Ptr++;
            }
            else
                return false;
        } 
        return true;
    }     
};


// 非递归的动态规划
// Runtime: 8 ms, faster than 87.25% of C++ online submissions for Interleaving String.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Interleaving String.
class Solution 
{
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        if (s1.length() + s2.length() != s3.length())
            return false;
        if (s1.length() == 0)
        {
            if (s2 == s3)
                return true;
            else
                return false;
        }
        if (s2.length() == 0)
        {
            if (s1 == s3)
                return true;
            else
                return false;
        }

        bool **memo = new bool*[s1.length() + 1];
        for (int i = 0; i <= s1.length(); i++)
            memo[i] = new bool[s2.length() + 1];

        for (int i = 0; i <= s1.length(); i++)
        {
            for (int j = 0; j <= s2.length(); j++)
            {
                if (i == 0 && j == 0)
                    memo[i][j] = true;
                else if (i == 0)
                    memo[i][j] = (memo[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                else if (j == 0)
                    memo[i][j] = (memo[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                else
                    memo[i][j] = (memo[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || 
                                 (memo[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        // 释放空间
        bool res = memo[s1.length()][s2.length()];
        delete[] memo;
        return res;
    }
};

// 节省空间版本的动态规划
// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Interleaving String.
// Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Interleaving String.

class Solution 
{
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        // 边界处理
        if (s1.length() + s2.length() != s3.length())
            return false;
        if (s1.length() == 0)
        {
            if (s2 == s3)
                return true;
            else
                return false;
        }
        if (s2.length() == 0)
        {
            if (s1 == s3)
                return true;
            else
                return false;
        }

        // 初始化
        bool *memo = new bool[s2.length() + 1];
        memo[0] = true;
        for (int i = 1; i <= s2.length(); i++)
        {
            if (s2.substr(0, i) == s3.substr(0, i))
                memo[i] = true;
            else
                memo[i] = false;
        }

        for (int i = 1; i <= s1.length(); i++)
        {
            if (s1.substr(0, i) == s3.substr(0, i))
                memo[0] = true;
            else
                memo[0] = false;

            for (int j = 1; j <= s2.length(); j++)
            {
                memo[j] = (memo[j] && s1[i - 1] == s3[i + j - 1]) || 
                          (memo[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        bool res = memo[s2.length()];
        delete[] memo;
        return res;
    }
};