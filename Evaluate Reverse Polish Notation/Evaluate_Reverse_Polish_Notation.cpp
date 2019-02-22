// 典型的利用堆栈的题目
// Runtime: 16 ms, faster than 100.00% of C++ online submissions for Evaluate Reverse Polish Notation.
// Memory Usage: 11.5 MB, less than 39.61% of C++ online submissions for Evaluate Reverse Polish Notation.
class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> memo;
        int res;

        for (auto token : tokens)
        {
            char chr = token[0];

            // 如果是数字的话就压入堆栈
            if (chr >= '0' && chr <= '9' || token.size() > 1)
                memo.push(atoi(token.c_str()));
                
            // 如果是运算符的话就要从堆栈中提取出两个运算数进行运算
            else
            {
                int op1 = memo.top();
                memo.pop();
                int op2 = memo.top();
                memo.pop();

                if (chr == '+')
                    res = op2 + op1;
                else if (chr == '-')
                    res = op2 - op1;
                else if (chr == '*')
                    res = op2 * op1;
                else if (chr == '/')
                    res = op2 / op1;
                
                memo.push(res);
            }
        }
        return memo.top();
    }
};