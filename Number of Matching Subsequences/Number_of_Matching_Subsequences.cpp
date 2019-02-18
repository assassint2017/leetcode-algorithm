// 如果字典中只要一个单词的话，使用线性的时间复杂度就可以解决，但是现在的问题在于有多个单词
// 如果假设单词的个数为k，string的长度为m，那么最笨的方法也可以使用km的时间来解决问题
// 所以需要一个加速算法,大概的思路就是用维护一个记录表来进行快速的查找

// Runtime: 188 ms, faster than 70.73% of C++ online submissions for Number of Matching Subsequences.
// Memory Usage: 42.7 MB, less than 100.00% of C++ online submissions for Number of Matching Subsequences.

class Solution 
{
public:
    int numMatchingSubseq(string S, vector<string>& words) 
    {
        // 建立记录表
        vector<int> dict[128];
        for (int i = 0; i < S.length(); i++)
            dict[S[i]].push_back(i);

        // 循坏的对每一个单词进行判断
        int res = 0;
        for (auto word : words)
        {
            bool found = true;
            for (int i = 0, pos = 0; i < word.length(); i++)
            {
                // 如果当前单词没有在记录表中出现的话，直接退出
                if (dict[word[i]].size() == 0)
                {
                    found = false;
                    break;
                }
                
                // binary search
                int leftPtr = 0, rightPtr = dict[word[i]].size() - 1;
                while (leftPtr < rightPtr)
                {
                    int midPtr = (leftPtr + rightPtr) / 2;
                    if (dict[word[i]][midPtr] < pos)
                        leftPtr = midPtr + 1;
                    else 
                        rightPtr = midPtr;
                }
                if (dict[word[i]][leftPtr] >= pos)
                    pos = dict[word[i]][leftPtr] + 1;
                else
                {
                    found = false;
                    break;
                }
            }
            if (found)
                res++;
        }
        return res;
    }
};