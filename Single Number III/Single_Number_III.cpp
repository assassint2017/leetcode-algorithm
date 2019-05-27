class Solution 
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        // 边界条件处理
        if (nums.size() < 2)
            return vector<int>(0);

        // 第一次遍历
        int res = 0;
        for (auto number : nums)
            res ^= number;
        
        for (int temp = 1; ; )
        {
            if (temp & res)
            {
                res = temp;
                break;
            }
            else
                temp <<= 1;
        }
        
        // 第二次遍历
        int res1 = 0, res2 = 0;
        for (auto number : nums)
        {
            if (res & number)
                res1 ^= number;
            else
                res2 ^= number;
        }

        vector<int> num;
        num.push_back(res1);
        num.push_back(res2);
        return num;
    }
};