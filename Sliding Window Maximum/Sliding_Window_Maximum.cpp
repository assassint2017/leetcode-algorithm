// 按照题目的要求，是线性的时间复杂度

// Runtime: 56 ms, faster than 94.55% of C++ online submissions for Sliding Window Maximum.
// Memory Usage: 13.2 MB, less than 44.28% of C++ online submissions for Sliding Window Maximum.

class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> res;

        // 边界条件处理
        if (nums.size() == 0)    
            return res;
        
        deque<int> memo;

        for (int i = 0; i < k; i++)
        {
            while (!memo.empty() && nums[i] > nums[memo.back()])
                memo.pop_back();
            memo.push_back(i);
        }

        for (int i = k; i < nums.size(); i++)
        {
            res.push_back(nums[memo.front()]);

            while (!memo.empty() && nums[i] > nums[memo.back()])
                memo.pop_back();
            memo.push_back(i);

            if (i - memo.front() >= k)
                memo.pop_front();
        }

        res.push_back(nums[memo.front()]);
        return res;
    }
};