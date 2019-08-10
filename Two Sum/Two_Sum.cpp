// 利用哈希表，线性的时间复杂度、线性的空间复杂度

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> hashmap;
        vector<int> res;
        
        for (int index = 0; index < nums.size(); ++index)
        {
            if (hashmap.find(target - nums[index]) == hashmap.end())
            {
                hashmap.insert(make_pair(nums[index], index));
            }
            else
            {
                res.push_back(hashmap.at(target - nums[index]));
                res.push_back(index);
                break;
            }
        }
        return res;
    }
};