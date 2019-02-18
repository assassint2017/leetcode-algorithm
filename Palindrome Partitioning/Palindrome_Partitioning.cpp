// 典型的回溯
// Runtime: 48 ms, faster than 64.52% of C++ online submissions for Palindrome Partitioning.
// Memory Usage: 19.1 MB, less than 100.00% of C++ online submissions for Palindrome Partitioning.

class Solution 
{
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> res;
        vector<string> vec;
        
        helper(s, vec, res);

        return res;
    }
private:
    void helper(string s, vector<string> &vec, vector<vector<string>> &res)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (isPalindrome(s.substr(0, i + 1)))
            {
                vec.push_back(s.substr(0, i + 1));
                
                if (i == s.length() - 1)
                    res.push_back(vec);

                helper(s.substr(i + 1), vec, res);
                vec.pop_back();
            }
        }
    }

    // 给定一个字符串，判断是否是回文的
    bool isPalindrome(string s)
    {
        for (int leftPtr = 0, rightPtr = s.length() - 1; leftPtr <= rightPtr; leftPtr++, rightPtr--)
        {
            if (s[leftPtr] != s[rightPtr])
                return false;
        }
        return true;
    }
};

// 下面是对上边的程序的优化加速
// Runtime: 16 ms, faster than 100.00% of C++ online submissions for Palindrome Partitioning.
// Memory Usage: 12.6 MB, less than 100.00% of C++ online submissions for Palindrome Partitioning.
// 可以去看看提交的代码中44ms和这个版本的区别，很小，就一处不一样
class Solution 
{
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> res;
        vector<string> vec;
        
        helper(0, s, vec, res);

        return res;
    }
private:
    void helper(int start, string &s, vector<string> &vec, vector<vector<string>> &res)
    {
        if (start == s.length())
        {
            res.push_back(vec);
            return;
        }
        for (int i = start; i < s.length(); i++)
        {
            // 44ms版本的代码，从这里看难道最大的速度瓶颈在substr这个函数？
            // string temp = s.substr(start, i - start + 1);
            // if (isPalindrome(temp, 0, i - start))
            if (isPalindrome(s, start, i))
            {
                vec.push_back(s.substr(start, i - start + 1));
                helper(i + 1, s, vec, res);
                vec.pop_back();
            }
        }
    }

    // 给定一个字符串，判断是否是回文的
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