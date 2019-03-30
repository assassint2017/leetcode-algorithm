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

// 第二种思路
// 使用快速排序的思想二分数据，达到线性的时间复杂度
// Runtime: 12 ms, faster than 98.21% of C++ online submissions for Kth Largest Element in an Array.
// Memory Usage: 9.5 MB, less than 56.68% of C++ online submissions for Kth Largest Element in an Array.
class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        return sort(nums, k, 0, nums.size() - 1);
    }
private:
    int sort(vector<int>& nums, int k, int left, int right)
    {
        if (left == right)
            return nums[left];
        
        int pivot = median3(nums, left, right);
        if (right - left == 1)
        {
            if (left == nums.size() - k)
                return nums[left];
            else
                return nums[right];
        }
        
        int leftptr = left, rightptr = right - 1;
        
        while (true)
        {
            while (nums[++leftptr] < pivot);
            while (rightptr > leftptr && nums[--rightptr] > pivot);
            
            if (leftptr < rightptr)
                swap(nums[leftptr], nums[rightptr]);
            else
                break;
        }
        if (leftptr < right)
            swap(nums[right - 1], nums[leftptr]);
        
        if (leftptr > nums.size() - k)
            return sort(nums, k, left, leftptr - 1);
        else if (leftptr < nums.size() - k)
            return sort(nums, k, leftptr + 1, right);
        else
            return pivot;
    }
    
    int median3(vector<int>& nums, int left, int right)
    {
        int mid = (left + right) / 2;
        if (nums[left] > nums[mid])
            swap(nums[left], nums[mid]);
        if (nums[left] > nums[right])
            swap(nums[left], nums[right]);
        if (nums[mid] > nums[right])
            swap(nums[mid], nums[right]);
        
        swap(nums[mid], nums[right - 1]);
        return nums[right - 1];
    }
};
