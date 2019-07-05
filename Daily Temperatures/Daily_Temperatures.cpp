// 解题思路
// 正向去做很难，那不如倒着来处理，对于这种明显的线性结构，可以考虑使用堆栈来处理

// Runtime: 196 ms, faster than 59.02% of C++ online submissions for Daily Temperatures.
// Memory Usage: 14.7 MB, less than 86.58% of C++ online submissions for Daily Temperatures.

class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& T) 
    {
        vector<int> res(T.size(), 0);
        stack<pair<int, int>> memo;

        for (int index = T.size() - 1; index >= 0 ; index--)
        {
            while (!memo.empty() && T[index] >= memo.top().first)
                memo.pop();

            if (!memo.empty())
                res[index] = memo.top().second - index;

            memo.push(make_pair(T[index], index));
        }
        
        return res;
    }
};