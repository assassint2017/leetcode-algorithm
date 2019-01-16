// 首先将数组调整成为一个最大堆，然后循环k-1次取出堆顶的元素，然后最后一次返回堆顶的元素即可
// 8ms 99.04%

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int maxSize = nums.size() - 1;
        
        createMaxHeap(nums);
            
        for (int i = 1; i <= k - 1; i++)
            deleteFromHeap(nums, maxSize--);
        
        return nums[0];
    }
    
    // 建立最大堆
    void createMaxHeap(vector<int> &maxHeap)
    {
        for (int i = maxHeap.size() - 1; i >= 0; i--)
        {
            helper(maxHeap, i);
        }
    }

    void helper(vector<int> &maxHeap, int index)
    {
        int temp = maxHeap[index];
        int parent, child;
        for (parent = index; parent * 2 + 1 <= maxHeap.size() - 1; parent = child)
        {
            child = parent * 2 + 1;
            if (child + 1 <= maxHeap.size() - 1 && maxHeap[child] < maxHeap[child + 1])
                child++;
            if (temp > maxHeap[child])
                break;
            else
                maxHeap[parent] = maxHeap[child];
        }
        maxHeap[parent] = temp;
    }

    // 从堆顶删除一个元素
    void deleteFromHeap(vector<int> &maxHeap, int maxSize)
    {
        int temp = maxHeap[maxSize];
        
        int parent, child;
        for (parent = 0; parent * 2 + 1 <= maxSize; parent = child)
        {
            // 计算左子树的索引
            child = parent * 2 + 1;

            // child 指向的是较大的那个子节点
            if (child + 1 <= maxSize && maxHeap[child] < maxHeap[child + 1])
                child++;
            
            // 如果根节点的值比两个子节点的值都要大，那么退出循环
            if (temp > maxHeap[child])
                break;
            else
                maxHeap[parent] = maxHeap[child];
        }

        maxHeap[parent] = temp;
    }
};