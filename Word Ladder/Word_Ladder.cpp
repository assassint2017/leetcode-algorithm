// 一上来的想法是使用dfs
// 这里其实仔细思考之后发现，无法使用备忘录，而不使用备忘录的话速度有跟不上
class Solution 
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        bool *visited = new bool[wordList.size()]();
        int res = dfs(beginWord, endWord, wordList, visited);

        delete[] visited;
        
        if (res == -99)
            return 0;
        else
            return res + 1;
        
    }
private:
    int dfs(string beginWord, string endWord, vector<string>& dict, bool* visited)
    {
        // 设置边界条件
        if (beginWord == endWord)
            return 0;

        int res = -99;
        for (int i = 0; i < dict.size(); i++)
        {
            if (visited[i] == false && match(beginWord, dict[i]))
            {
                visited[i] = true;
                int temp = dfs(dict[i], endWord, dict, visited);

                if (temp != -99)
                {
                    if (res == -99)
                        res = temp + 1;
                    else
                        res = min(res, temp + 1);
                }
                visited[i] = false;
            }
        }
        return res;
    }

    // 给定两个字符串，判断是否可以由一个字符串改变一个字母成为第二个字符串
    bool match(string word1, string word2)
    {
        int numOfMisMatch = 0;
        for (int ptr = 0; ptr < word1.length(); ptr++)
        {
            if (word1[ptr] != word2[ptr])
                numOfMisMatch++;
            if (numOfMisMatch > 1)
                return false;
        }

        if (numOfMisMatch == 0)
            return false;
        else
            return true;
    }
};


// 其实对于这种最短路径的问题，更适合使用bfs，因为bfs一旦搜索到，就一定是最优解，而dfs必须要进行全局搜索才能确定
// bfs
// 代码的结构是很经典的广度优先搜索

// Runtime: 84 ms, faster than 85.52% of C++ online submissions for Word Ladder.
// Memory Usage: 13.1 MB, less than 67.05% of C++ online submissions for Word Ladder.

class Solution 
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        queue<string> candidate;
        candidate.push(beginWord);

        int minLength = 1;
        while (!candidate.empty())
        {
            for (int size = candidate.size(); size > 0; size--)
            {
                string word = candidate.front();
                candidate.pop();

                if (word == endWord)
                    return minLength;
                else
                    helper(candidate, dict, word);
                
            }
            minLength++;
        }

        // 如果没有这样的变换，就返回0
        return 0;
    }
private:
    void helper(queue<string>& candidate, unordered_set<string>& dict, string word)
    {
        // 把自己先删掉
        dict.erase(word);
        for (int i = 0; i < word.length(); i++)
        {
            char temp = word[i];
            for (int j = 0; j < 26; j++)
            {
                word[i] = 'a' + j;
                if (dict.find(word) != dict.end())
                {
                 candidate.push(word);
                    dict.erase(word);
                }
            }
            word[i] = temp;
        }
    }
};
