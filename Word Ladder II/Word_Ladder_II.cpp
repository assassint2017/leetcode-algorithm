// BFS + DFS

// Runtime: 116 ms, faster than 89.67% of C++ online submissions for Word Ladder II.
// Memory Usage: 20.6 MB, less than 70.30% of C++ online submissions for Word Ladder II.

typedef unordered_set<string> HashSet;
typedef unordered_map<string, vector<string>> HashMap;
typedef queue<string> Queue;
typedef vector<vector<string>> Res;
typedef vector<string> myStack;

class Solution 
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        Res res;  // 保存最终的结果
        HashSet candidate(wordList.begin(), wordList.end()), memo;  // memo的作用是不允许本层的节点相连
        myStack tempmemo;
        HashMap hashmap;  // 用来保存从endword指向beginword的树形结构
        
        Queue todo;
        todo.push(beginWord);
        
        bool finished = false;
        while (!todo.empty() && !finished)
        {
            for (int size = todo.size(); size > 0; size--)
            {
                string word = todo.front();
                todo.pop();

                if (helper(word, endWord, candidate, hashmap, todo, tempmemo, memo))
                    finished = true;
            }
            while (!tempmemo.empty())
            {
                memo.insert(tempmemo.back());
                tempmemo.pop_back();
            }
        }

        if (finished)
        {
            myStack stack;
            stack.push_back(endWord);
            dfs(endWord, hashmap, res, stack);
        }
        return res;
    }
private:
    bool helper(string word, string& endWord, HashSet& candidate, HashMap& hashmap, Queue& todo, myStack& tempmemo, HashSet& memo)
    {
        string originWord = word;
        candidate.erase(word);

        for (int i = 0; i < word.length(); i++)
        {
            char temp = word[i];
            for (int j = 0; j < 26; j++)
            {
                word[i] = 'a' + j;
                if (candidate.find(word) != candidate.end() && memo.find(word) == memo.end())
                {
                    auto iter = hashmap.find(word);
                    if (iter == hashmap.end())
                    {
                        hashmap.insert(make_pair(word, myStack(1, originWord)));
                        todo.push(word);
                        tempmemo.push_back(word);
                    }
                    else
                        iter->second.push_back(originWord);   

                    if (word == endWord)   
                        return true;
                }
            }
            word[i] = temp;
        }
        return false;
    }

    void dfs(string endWord, HashMap& hashmap, Res& res, myStack& stack)
    {
        if (hashmap.find(endWord) != hashmap.end())
        {
            for (auto word : hashmap.at(endWord))
            {
                stack.push_back(word);
                dfs(word, hashmap, res, stack);
                stack.pop_back();
            }
        }
        else
        {
            vector<string> tempRes;
            for (int i = stack.size() - 1; i >= 0; i--)
                tempRes.push_back(stack[i]);
            res.push_back(tempRes);
        }
    }
};