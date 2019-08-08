// 最差最差是n3的时间复杂度、n的空间复杂度
// 改进之后可以是n2的时间复杂度、n的空间复杂度
// 目前追求的是n的时间复杂度、n的空间复杂度

// Runtime: 40 ms, faster than 80.79% of C++ online submissions for Degree of an Array.
// Memory Usage: 12.4 MB, less than 100.00% of C++ online submissions for Degree of an Array.

struct cell
{
    cell (int i) : times(1), index(i) {}
    int times;
    const int index;
};

class Solution 
{
public:
    int findShortestSubArray(vector<int>& nums) 
    {
        unordered_map<int, cell> hashmap;
        int maxDegree = 0;
        int minLength = 0;
        
        for (int index = 0; index < nums.size(); ++index)
        {
            int length = 1;

            // 将数据插入到哈希表中
            if (hashmap.find(nums[index]) == hashmap.end())
                hashmap.insert(pair<int, cell>(nums[index], cell(index)));
            else
            {
                cell& temp = hashmap.at(nums[index]);
                temp.times += 1;
                length = index - temp.index + 1;
            }
            
            // 更新数组的度以及最小长度
            cell& temp = hashmap.at(nums[index]);
            if (maxDegree <= temp.times)
            {
                if (maxDegree == temp.times)
                    minLength = min(length, minLength);
                else
                    minLength = length;
                
                maxDegree = temp.times;
            }
        }
        return minLength;
    }
};