// 使用和上一道题目同样的回溯算法
// 31 / 39 test cases passed. 超时了
class Solution 
{
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        vector<string> res, curstr;
        helper(s, curstr, wordDict, res);
        return res;
    }
private:
    void helper(string s, vector<string>& curstr, vector<string>& wordDict, vector<string>& res)
    {
        if (s.length() == 0)
        {
            string resstr = "";

            for (auto word : curstr)
                resstr = resstr + word + ' ';
            resstr.pop_back();
    
            res.push_back(resstr);
        }        

        for (auto word : wordDict)
        {
            if (s.substr(0, word.length()) == word)
            {
                curstr.push_back(word);
                helper(s.substr(word.length()), curstr, wordDict, res);
                curstr.pop_back();
            }
        }
    }
};


// 思路二 相比于思路一 加入备忘录
// 这道题目的启示是：深度优先搜索是会走重复的

// Runtime: 24 ms, faster than 70.41% of C++ online submissions for Word Break II.
// Memory Usage: 13.1 MB, less than 53.33% of C++ online submissions for Word Break II.

typedef unordered_map<int, vector<string>> HashMap;
class Solution 
{
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        HashMap hashmap;
        return helper(s, wordDict, hashmap);
    }
private:
    vector<string> helper(string s, vector<string>& wordDict, HashMap& hashmap)
    {
        if (hashmap.find(s.length()) == hashmap.end())
        {
            vector<string> res;
            for (auto word : wordDict)
            {
                if (s.substr(0, word.length()) == word)
                {
                    string nextstr = s.substr(word.length());
                    if (nextstr == "")
                        res.push_back(word);
                    else
                    {
                        for (auto str : helper(nextstr, wordDict, hashmap))
                            res.push_back(word + " " + str);    
                    }
                }
            }
            hashmap.insert(make_pair(s.length(), res));
        }
        return hashmap.at(s.length());
    }
};