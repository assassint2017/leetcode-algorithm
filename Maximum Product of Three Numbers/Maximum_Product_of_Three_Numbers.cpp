// 第一种方式 线性的时间复杂度 手动维度若干个变量来记录最大值和最小值
// Runtime: 48 ms, faster than 81.12% of C++ online submissions for Maximum Product of Three Numbers.
// Memory Usage: 10.9 MB, less than 86.67% of C++ online submissions for Maximum Product of Three Numbers.

class Solution 
{
public:
    int maximumProduct(vector<int>& nums) 
    {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;

        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for (auto num : nums)
        {
            // 手动更新三个最大值
            if (num >= max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (num >= max2)
            {
                max3 = max2;
                max2 = num;
            }
            else if (num > max3)
                max3 = num;

            // 手动更新两个最小值
            if (num <= min1)
            {
                min2 = min1;
                min1 = num;
            }
            else if (num < min2)
                min2 = num;
        }

        int res1 = max1 * max2 * max3;
        int res2 = max1 * min1 * min2;
        return max(res1, res2);
    }
};


// 如果题目问最大的N个数相乘的话，手动维护变量就不太方便了，因此可以考虑使用最大堆和最小堆的方式
// Runtime: 48 ms, faster than 81.12% of C++ online submissions for Maximum Product of Three Numbers.
// Memory Usage: 11 MB, less than 66.67% of C++ online submissions for Maximum Product of Three Numbers.
class Solution 
{
public:
    int maximumProduct(vector<int>& nums) 
    {
        // 初始化最小堆和最大堆
        vector<int> maxHeap;
        vector<int> minHeap;

        for (int i = 0; i < 3; ++i)
        {
            maxHeap.push_back(nums[i]);
            minHeap.push_back(nums[i]);
        }
        
        sort(maxHeap.begin(), maxHeap.end());
        maxHeap.pop_back();

        auto great = [](const int& item1, const int& item2){return item1 > item2;};
        make_heap(minHeap.begin(), minHeap.end(), great);

        // 循环插入
        for (int i = 3; i < nums.size(); ++i)
        {
            if (nums[i] < maxHeap[0])
            {
                pop_heap(maxHeap.begin(), maxHeap.end());
                maxHeap.pop_back();

                maxHeap.push_back(nums[i]);
                push_heap(maxHeap.begin(), maxHeap.end());
            }

            if (nums[i] > minHeap[0])
            {
                pop_heap(minHeap.begin(), minHeap.end(), great);
                minHeap.pop_back();

                minHeap.push_back(nums[i]);
                push_heap(minHeap.begin(), minHeap.end(), great);
            }
        }

        // 计算最终结果
        int res1 = minHeap[0] * minHeap[1] * minHeap[2];
        int res2 = max(minHeap[1], minHeap[2]) * maxHeap[0] * maxHeap[1];
        return max(res1, res2);
    }
};