// 深度优先搜索 + 备忘录

// 这道题目的意思之前没有理解正确，它问的是先手玩家有没有机会可以赢得比赛
// 题目中force win的意思应该是先手玩家有没有机会下完一步旗之后将后手玩家将军
// 意思就是这时候无论后手玩家干啥，都阻止不了先手玩家锁定胜局

// Runtime: 292 ms, faster than 24.38% of C++ online submissions for Can I Win.
// Memory Usage: 53.2 MB, less than 11.59% of C++ online submissions for Can I Win.

typedef unordered_map<string, bool> HashMap;
class Solution 
{
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) 
    {
        // 处理两种非常简单的边界情况
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
            return false;
        if (maxChoosableInteger >= desiredTotal)
            return true;
        
        string states(maxChoosableInteger, 'F');
        HashMap hashmap;
        
        return helper(desiredTotal, states, hashmap);
    }
private:
    bool helper(int desiredTotal, string& states, HashMap& hashmap)
    {
        // 如果当前的状态在哈希表中，则直接返回结果即可
        if (hashmap.find(states) != hashmap.end())
            return hashmap.at(states);       

        for (int i = 0; i < states.length(); i++)
        {
            if (states[i] == 'F')
            {
                states[i] = 'T';
                if (i + 1 >= desiredTotal || !helper(desiredTotal - i - 1, states, hashmap))
                {
                    states[i] = 'F';
                    hashmap.insert(make_pair(states, true));
                    return true;
                }
                else
                    states[i] = 'F';
            }
        }
        hashmap.insert(make_pair(states, false));
        return false;
    }
};