// 首先需要对给定的字典建立一个前缀树，然后使用深度优先搜索进行查找

// Runtime: 52 ms, faster than 84.90% of C++ online submissions for Longest Word in Dictionary.
// Memory Usage: 29.5 MB, less than 30.00% of C++ online submissions for Longest Word in Dictionary.

struct TrieNode
{
    bool isWord = false;
    TrieNode* next[26] = {nullptr};
};

class Solution 
{
public:

    Solution () : root(new TrieNode()) {}

    ~Solution () { clear(root); }

    string longestWord(vector<string>& words) 
    {
        // 建立字典树
        buildTire(words);
        
        string res = "", candidate = "";

        dfs(root, res, candidate);
        
        return res;
    }
private:
    TrieNode* root = nullptr;
    
private:
    void buildTire(vector<string>& words)
    {   
        // 迭代插入
        for (auto word : words)
        {
            TrieNode* head = root;
            
            for (int index = 0; index < word.length(); ++index)
            {
                if (head->next[word[index] - 'a'] == nullptr)
                {
                    TrieNode* node = new TrieNode();
                    head->next[word[index] - 'a'] = node;
                }
                head = head->next[word[index] - 'a'];
                if (index == word.length() - 1)
                    head->isWord = true;
            }
        }
    }
    
    void dfs(TrieNode* root, string& res, string& candidate)
    {
        if (root == nullptr)
            return ;
        
        for (int i = 0; i < 26; ++i)
        {
            if (root->next[i] != nullptr && root->next[i]->isWord)
            {
                candidate.push_back('a' + i);

                if (candidate.length() > res.length() || (candidate.length() == res.length() && candidate < res))
                    res = candidate;
                
                dfs(root->next[i], res, candidate);

                candidate.pop_back();
            }
        }
    }

    void clear(TrieNode* root)
    {
        if (root == nullptr)
            return ;

        for (int i = 0; i < 26; ++i)
            clear(root->next[i]);
        delete root;
    }
};