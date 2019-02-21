// 简单的回溯 29 / 36 test cases passed. 超时了
class Solution 
{
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        if (s.length() == 0)
            return true;
        
        for (int i = 0; i < s.length(); i++)
        {
            if (inWordDict(s.substr(0, i + 1), wordDict) && wordBreak(s.substr(i + 1), wordDict))
                return true;
        }
        return false;
    }
private:
    bool inWordDict(string &s, vector<string> &wordDict)
    {
        for (auto str: wordDict)
        {
            if (s == str)
                return true;
        }
        return false;
    }
};

// 思路二 同样使用回溯，区别在于对于思路一的代码进行加速
// 29 / 36 test cases passed. 同样超时了
class Solution 
{
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        if (s.length() == 0)
            return true;

        for (auto word : wordDict)
        {
            if (s.substr(0, word.length()) == word)
            {
                if (wordBreak(s.substr(word.length()), wordDict))
                    return true;
            }
        }
        return false;   
    }
};


// 思路三 区别与思路二就是加入了备忘录
// Runtime: 8 ms, faster than 99.55% of C++ online submissions for Word Break.
// Memory Usage: 9.9 MB, less than 87.92% of C++ online submissions for Word Break.

class Solution 
{
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        bool *visited = new bool[s.length() + 1]();
        
        bool res = helper(s, wordDict, visited);
        
        delete[] visited;
        
        return res;
    }
private:
    bool helper(string s, vector<string>& wordDict, bool* visited)
    {
        if (visited[s.length()])
            return false;
        else
        {
            if (s.length() == 0)
                return true;

            for (auto word : wordDict)
            {
                if (s.substr(0, word.length()) == word)
                {
                    if (helper(s.substr(word.length()), wordDict, visited))
                        return true;
                }
            }
            visited[s.length()] = true;
            return false;     
        }
    }
};