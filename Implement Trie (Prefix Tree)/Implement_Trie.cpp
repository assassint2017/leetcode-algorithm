// 实现一个字典树，这里需要注意一下析构的问题
// Runtime: 76 ms, faster than 65.71% of C++ online submissions for Implement Trie (Prefix Tree).
// Memory Usage: 45.6 MB, less than 20.00% of C++ online submissions for Implement Trie (Prefix Tree).

struct TrieNode
{
	TrieNode(char chr) : chr(chr) {}

	char chr;
    bool isWord = false;
	TrieNode* next[26] = {nullptr};
};

class Trie 
{
public:
    /** Initialize your data structure here. */
    Trie() 
    {
        root = new TrieNode(0);
    }

    ~Trie()
    {
        clear(root);
    }

    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        TrieNode* head = root;
        for (int index = 0; index < word.length(); ++index)
        {
            if (head->next[word[index] - 'a'] == nullptr)
            {
                TrieNode* node = new TrieNode(word[index]);    
                head->next[word[index] - 'a'] = node;
            }
            head = head->next[word[index] - 'a'];
            if (index == word.length() - 1)
                head->isWord = true;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        TrieNode* node = find(word);
        return node != nullptr && node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        return find(prefix) != nullptr;
    }

private:
    TrieNode* root;

    TrieNode* find(const string& str)
    {
        if (str.length() == 0) return nullptr;

        int index = 0;
        TrieNode* head = root;

        while (index != str.length())
        {
            if (head->next[str[index] - 'a'] == nullptr)
                return nullptr;
            else
            {
                head = head->next[str[index] - 'a'];
                ++index;
            }
        }
        return head;
    }

    void clear(TrieNode* root)
    {
        if (root == nullptr) return ;
        for (int i = 0; i < 26; ++i)
            clear(root->next[i]);
        delete root;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */