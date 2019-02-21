// 题目要求是on的时间复杂度，首先使用nlgn的排序思想解决问题

// Runtime: 12 ms, faster than 99.79% of C++ online submissions for Longest Consecutive Sequence.
// Memory Usage: 9 MB, less than 98.36% of C++ online submissions for Longest Consecutive Sequence.

class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if (nums.size() == 0)    
            return 0;
        
        sort(nums.begin(), hashmap.end());
        
        int maxLength = 1;
        for (int i = 1, length = 1; i < nums.size(); i++)
        {
            if (num == nums[i - 1] + 1)
            {
                length++;
                maxLength = max(maxLength, length);
            }
            else if (num == nums[i - 1])
                ;
            else
                length = 1;
        }
        return maxLength;
    }
};

// 思路二，on的时间复杂度的版本
// Runtime: 16 ms, faster than 71.73% of C++ online submissions for Longest Consecutive Sequence.
// Memory Usage: 10.2 MB, less than 37.71% of C++ online submissions for Longest Consecutive Sequence.
class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_map<int, int> hashmap;
        int maxLength = 0;

        // 对数组中的每一个数字进行O(1)的计算
        for (auto num : nums)
        {
            // 如果当前数字已经存在于哈希表中，就没有必要二次操作了
            if (hashmap.find(num) == hashmap.end())
            {
                auto rightIter = hashmap.find(num + 1);
                auto leftIter = hashmap.find(num - 1);

                int left = leftIter == hashmap.end() ? 0 : leftIter->second;
                int right = rightIter ==  hashmap.end() ? 0 : rightIter->second;

                int length = left + right + 1;
                maxLength = max(maxLength, length);

                hashmap.insert(make_pair(num, length));
                
                hashmap.at(num - left) = length;
                hashmap.at(num + right) = length;
            }
        }
        return maxLength;
    }
};