// 使用动态规划的思路进行解决
// Runtime: 4 ms, faster than 95.97% of C++ online submissions for Decode Ways.
// Memory Usage: 8.7 MB, less than 14.92% of C++ online submissions for Decode Ways.

class Solution 
{
public:
    int numDecodings(string s) 
    {
        // 边界条件处理
        if (s.length() == 0)
            return 0;

        vector<int> res(s.length() + 1, 0);

        // 初始化边界
        res[s.length()] = 1;
        if (s[s.length() - 1] != '0')
            res[s.length() - 1] = 1;
        
        for (int i = s.length() - 2; i >= 0; i--)
        {
            if (s[i + 1] == '0')
            {
                if (s[i] == '1' || s[i] == '2')
                    res[i] = res[i + 2];
                else
                    // 有一些情况下，是无法解码数据的，比如连续的两个0，或者90，80等
                    return 0;
            }
            else if (s[i] == '0')
                continue;
            else if (s[i] >= '3' || (s[i] == '2' && s[i + 1] > '6'))
                res[i] = res[i + 1];
            else
                res[i] = res[i + 1] + res[i + 2];
        }
        return res[0];
    }
};