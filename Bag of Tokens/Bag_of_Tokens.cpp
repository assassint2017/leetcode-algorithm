// 核心的思路是贪心
// 对于使用代币换取分数，明显应该选取消耗能量最小的
// 对于使用代币换取能量，明显应该选择获取能量最大的

// Runtime: 8 ms, faster than 16.67% of C++ online submissions for Bag of Tokens.
// Memory Usage: 786.4 KB, less than 100.00% of C++ online submissions for Bag of Tokens.

#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    int bagOfTokensScore(vector<int>& tokens, int P) 
    {
        // 首先对代币进行从小到大的排序
        vector<int> sortTokens = tokens;
        sort(sortTokens.begin(), sortTokens.end());

        // 初始化两个指针，一个指向最小值，另一个指向最大值
        int minPtr = 0, maxPtr = sortTokens.size() - 1;

        int score = 0;
        
        while (true)
        {
            // 兑换积分
            while (minPtr <= maxPtr && P >= sortTokens[minPtr])
            {
                P -= sortTokens[minPtr++];
                score++;
            }

            // 边界
            if (maxPtr - minPtr < 2)
                return score;
            
            // 兑换能量
            if (score > 0)
            {
                score--;
                P += sortTokens[maxPtr--];
            }
            else
                return 0;
        }
    }
};