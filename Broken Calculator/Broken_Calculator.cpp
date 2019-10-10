// 根据题目说明，两者都是正数
// 基本思路是使用广度优先搜索，但是很明显的超时了
// 明显超时

class Solution 
{
public:
    int brokenCalc(int start, int end) 
    {
        if (start >= end)
        {
            return start - end;
        }
        
        queue<int> memo;
        memo.push(start);
        
        int layer = 0;
        while (!memo.empty())
        {
            for (int i = memo.size(); i > 0; --i)
            {
                int temp = memo.front();
                memo.pop();

                if (temp == end)
                {
                    return layer;
                }

                if (temp > 1) memo.push(temp - 1);
                if (temp < end) memo.push(temp * 2);
            }
            ++layer;
        }
        
        return -1;
    }
};

// 改成递归贪心
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Broken Calculator.
// Memory Usage: 8.2 MB, less than 80.00% of C++ online submissions for Broken Calculator.

class Solution 
{
public:
    int brokenCalc(int start, int end) 
    {
        if (start >= end)
        {
            return start - end;
        }
        
        if (end % 2 == 0)
        {
            return brokenCalc(start, end / 2) + 1;
        }
        else
        {
            return brokenCalc(start, end + 1) + 1;
        }
    }
};