// 附参考链接，整体思路还是挺好的
// https://leetcode.com/problems/longest-string-chain/discuss/294890/C%2B%2BJavaPython-DP-Solution

// Runtime: 60 ms, faster than 82.89% of C++ online submissions for Longest String Chain.
// Memory Usage: 15.5 MB, less than 100.00% of C++ online submissions for Longest String Chain.

class Solution 
{
public:
    int longestStrChain(vector<string>& words) 
    {
        // 按照字符串的长度从小到大进行排序
        auto comp = [](const string& word1, const string& word2){return word1.length() < word2.length();};
        sort(words.begin(), words.end(), comp);
        
        unordered_map<string, int> hashmap;
        vector<int> dp(words.size(), 1);
        int res = 1;
        
        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = 0; j < words[i].length(); ++j)
            {
                string substr = words[i].substr(0, j) + words[i].substr(j + 1);
                if (hashmap.find(substr) != hashmap.end())
                    dp[i] = max(dp[i], dp[hashmap.at(substr)] + 1);    
            }
            res = max(res, dp[i]);
            hashmap.insert(pair<string, int>(words[i], i));
        }
        return res;
    }
};