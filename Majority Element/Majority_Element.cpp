// 对于这道题目，可以使用哈希表或者排序，但是还有一种特殊的算法，专门解决这类的问题
// Boyer-Moore投票算法

// Runtime: 20 ms, faster than 99.42% of C++ online submissions for Majority Element.
// Memory Usage: 11.1 MB, less than 100.00% of C++ online submissions for Majority Element.

class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int count = 0;
        int res;

        for (auto num : nums)
        {
            if (count == 0)
                res = num;
            
            if (res == num)
                count++;
            else
                count--;
        }
        return res;
    }
};