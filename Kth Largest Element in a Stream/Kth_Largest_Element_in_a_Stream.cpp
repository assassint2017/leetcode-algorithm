// Runtime: 52 ms, faster than 52.57% of C++ online submissions for Kth Largest Element in a Stream.
// Memory Usage: 19.5 MB, less than 65.00% of C++ online submissions for Kth Largest Element in a Stream.

class KthLargest 
{
public:
    KthLargest(int k, vector<int>& nums) 
    {
        size = k;
        for (int i = 0; i < k && i < nums.size(); ++i)
            minHeap.push_back(nums[i]);
        
        make_heap(minHeap.begin(), minHeap.end(), comp);   
        
        for (int i = k; i < nums.size(); ++i)
        {
            if (nums[i] > minHeap[0])
            {
                pop_heap(minHeap.begin(), minHeap.end(), comp);
                minHeap.pop_back();
                
                minHeap.push_back(nums[i]);
                push_heap(minHeap.begin(), minHeap.end(), comp);
            }
        }
    }

    int add(int val) 
    {
        if (size != minHeap.size())
        {
            minHeap.push_back(val);
            push_heap(minHeap.begin(), minHeap.end(), comp);   
        }
        else
        {
            if (val > minHeap[0])
            {
                pop_heap(minHeap.begin(), minHeap.end(), comp);
                minHeap.pop_back();

                minHeap.push_back(val);
                push_heap(minHeap.begin(), minHeap.end(), comp);
            }
        }
        return minHeap[0];
    }
private:
    int size;
    vector<int> minHeap;
    bool (*comp)(const int&, const int&) = [](const int& num1, const int& num2){return num1 > num2;};
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */