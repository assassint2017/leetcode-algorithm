// 直接一步到位的把每一个元素放到指定的位置上
// 这种思路有一个问题，就是如果nums的长度和k存在一个公因子的时候，就无法返回正确结果
// 因此，就需要使用一个变量来记录每次开始的索引位置，如果存在公因子的情况下，回到了最开始出发的索引，这时候就从最开始的位置的下一个开始就行
class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        if (nums.size() == 0)
            return;

        // 首先简化一下k
        int length = nums.size();
        k %= length;

        if (k == 0)
            return;

        // 记录当前已经移动了多少个元素
        for (int curlength = 0, startidnex = 0, index = 0, temp1 = nums[index], temp2; curlength != length; curlength++)
        {
            int newindex = (index + k) % length;
            temp2 = nums[newindex];
            nums[newindex] = temp1;

            if (newindex == startidnex)
            {
                index = startidnex = newindex + 1;
                temp1 = nums[index];
            }
            else
            {
                temp1 = temp2;
                index = newindex;
            }
        }
    }
};