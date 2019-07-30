// 附参考链接
// https://leetcode.com/problems/multiply-strings/discuss/17605/Easiest-JAVA-Solution-with-Graph-Explanation

// Runtime: 8 ms, faster than 68.69% of C++ online submissions for Multiply Strings.
// Memory Usage: 8.8 MB, less than 57.41% of C++ online submissions for Multiply Strings.

class Solution 
{
public:
    string multiply(string num1, string num2) 
    {
        vector<char> memo(num1.size() + num2.size(), 0);

        for (int i = num1.size() - 1; i >= 0; --i)
        {
            for (int j = num2.size() - 1; j >= 0; --j)
            {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int pos1 = i + j, pos2 = i + j + 1;
                int sum = mul + memo[pos2];

                memo[pos2] = sum % 10;
                memo[pos1] += (sum / 10);
            }
        }

        int nonzero = 0;
        for (; nonzero < memo.size(); ++nonzero)
            if (memo[nonzero] != 0)
                break;
        
        if (nonzero == memo.size()) return "0";

        string res = "";
        for (int i = nonzero; i < memo.size(); ++i)
            res += (memo[i] + '0');
        return res;
    }
};