// 经典的广度优先搜索

// Runtime: 132 ms, faster than 79.06% of C++ online submissions for Open the Lock.
// Memory Usage: 33.9 MB, less than 53.85% of C++ online submissions for Open the Lock.

class Solution 
{
public:
    int openLock(vector<string>& deadends, string target) 
    {
        // 初始状态为 0000
        string curState(4, '0');

        unordered_set<string> deadwords(deadends.begin(), deadends.end());
        unordered_set<string> hashset;

        queue<string> q;
        q.push(curState);
        hashset.insert(curState);

        int res = 0;
        while (!q.empty())
        {
            for (int size = q.size(); size > 0; size--)
            {
                curState = q.front();
                q.pop();

                if (curState == target)
                    return res;
                else if (deadwords.find(curState) != deadwords.end())
                    continue;
                else
                    candidate(q, hashset, curState); 
            }
            res++;
        }  
        return -1;
    }

    void candidate(queue<string>& q, unordered_set<string>& hashset, string& curState)
    {
        for (int i = 0; i < 4; i++)
        {
            char old = curState[i];
            
            curState[i] = curState[i] == '9' ? '0' : curState[i] + 1;
            if (hashset.find(curState) == hashset.end())
            {
                q.push(curState);
                hashset.insert(curState);
            }
            curState[i] = old;

            curState[i] = curState[i] == '0' ? '9' : curState[i] - 1;           
            if (hashset.find(curState) == hashset.end()) 
            {
                q.push(curState);
                hashset.insert(curState);
            }
            curState[i] = old;
        }
    }
};