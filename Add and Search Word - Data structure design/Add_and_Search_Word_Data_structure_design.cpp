// 这道题目最笨的方法就是暴力匹配，但是必定超时
// 这道题目还可以使用前缀树来解决

// Runtime: 100 ms, faster than 66.14% of C++ online submissions for Add and Search Word - Data structure design.
// Memory Usage: 44.9 MB, less than 81.82% of C++ online submissions for Add and Search Word - Data structure design.

struct TrieNode
{
    TrieNode(char chr) : chr(chr) {}
    char chr;
    bool isWord = false;
    TrieNode* next[26] = {nullptr};
};

class WordDictionary 
{
public:
    WordDictionary() : root(new TrieNode(0)) {}

    ~WordDictionary() { clear(root); }
    
    /** Adds a word into the data structure. */
    void addWord(string word) 
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
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) 
    {
        return word.length() == 0 ? false : search(word, 0, root);
    }

private:
    TrieNode* root;

    bool search(const string& word, int index, TrieNode* root)
    {   
        if (index == word.length())
            return root->isWord ? true : false;           

        if (word[index] != '.')
        {
            if (root->next[word[index] - 'a'] == nullptr)
                return false;
            else
                return search(word, index + 1, root->next[word[index] - 'a']);
        }
        else
        {
            for (int i = 0; i < 26; ++i)   
                if (root->next[i] != nullptr && search(word, index + 1, root->next[i]))
                    return true;
            return false;
        }
    }

    void clear(TrieNode* root)
    {
        if (root == nullptr) return ;
        for (int i = 0; i < 26; ++i)
            clear(root->next[i]);
        delete root;
    }
};