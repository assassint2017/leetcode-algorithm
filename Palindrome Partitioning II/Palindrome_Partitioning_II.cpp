// 思路一，使用和131同样的回溯思路 24 / 29 test cases passed. 超时了
// 代码略
// 思路二，简单递归动态规划 26 / 29 test cases passed. 超时了
// 思路三，基于备忘录的动态规划
// Runtime: 352 ms, faster than 12.50% of C++ online submissions for Palindrome Partitioning II.
// Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for Palindrome Partitioning II.

class Solution 
{
public:
    int minCut(string s) 
    {
        int *memo = new int[s.length() + 1];
        for (int i = 0; i <= s.length(); i++)
            memo[i] = -1;
        
        int res = helper(0, s, memo); 
        delete[] memo;
        return res;
    }

private:
    int helper(int start, string &s, int *memo)
    {
        if (memo[start] == -1)
        {
            if (isPalindrome(s, start, s.length() - 1))
                memo[start] = 0;
            else
            {
                memo[start] = INT_MAX;
                for (int i = start; i < s.length() - 1; i++)
                {
                    if (isPalindrome(s, start, i))
                        memo[start] = min(memo[start], helper(i + 1, s, memo) + 1);
                }
            }
        }
        return memo[start];
    }

    // 给定一个字符串，判断从起点到终点的子字符串是否是回文的
    bool isPalindrome(string &s, int start, int end)
    {
        for (int leftPtr = start, rightPtr = end; leftPtr <= rightPtr; leftPtr++, rightPtr--)
        {
            if (s[leftPtr] != s[rightPtr])
                return false;
        }
        return true;
    }
};

// 思路四 自底向上的动态规划
// Runtime: 360 ms, faster than 17.76% of C++ online submissions for Palindrome Partitioning II.
// Memory Usage: 8.4 MB, less than 98.92% of C++ online submissions for Palindrome Partitioning II.

class Solution 
{
public:
    int minCut(string s) 
    {
        int *res = new int[s.length() + 1];
        for (int i = s.length(); i >= 0; i--)
        {
            if (isPalindrome(s, i, s.length() - 1))
                res[i] = 0;
            else
            {
                res[i] = INT_MAX;
                for (int j = i; j < s.length() - 1; j++)
                {
                    if (isPalindrome(s, i, j))
                        res[i] = min(res[i], res[j + 1] + 1);
                }
            }
        }

        int numCut = res[0]; 
        delete[] res;
        return numCut;
    }

private:
    // 给定一个字符串，判断从起点到终点的子字符串是否是回文的
    bool isPalindrome(string &s, int start, int end)
    {
        for (int leftPtr = start, rightPtr = end; leftPtr <= rightPtr; leftPtr++, rightPtr--)
        {
            if (s[leftPtr] != s[rightPtr])
                return false;
        }
        return true;
    }
};

// 思路五 上边的四种思路速度瓶颈在于判断函数，确实效率太低了
// 因此一种聪明的做法如下
// https://leetcode.com/problems/palindrome-partitioning-ii/discuss/42212/Two-C%2B%2B-versions-given-(one-DP-28ms-one-Manancher-like-algorithm-10-ms)

// Runtime: 24 ms, faster than 81.58% of C++ online submissions for Palindrome Partitioning II.
// Memory Usage: 12.4 MB, less than 26.88% of C++ online submissions for Palindrome Partitioning II.

class Solution 
{
public:
    int minCut(string s) 
    {
        if (s.length() < 2)
            return 0;

        // memo[i][j] 代表从下标为i到下标为j的子字符串是否是回文的
        bool **memo = new bool*[s.length()];
        for (int i = 0; i < s.length(); i++)
        {
            memo[i] = new bool[s.length()];
            for (int j = 0; j < s.length(); j++)
                memo[i][j] = false;
        }

        // res[i]代表从下标为i到string s最后的子字符串的最小cut数量
        int *res = new int[s.length() + 1];
        for (int i = 0; i < s.length(); i++)
            res[i] = INT_MAX;
        res[s.length()] = -1;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            for (int j = i; j < s.length(); j++)
            {
                if (s[i] == s[j] && (j - i < 2 || memo[i + 1][j - 1]))
                {
                    memo[i][j] = true;
                    res[i] = min(res[i], res[j + 1] + 1);
                }
            }
        }
        
        int numCut = res[0];
        delete[] res;
        delete[] memo;
        return numCut;
    }
};