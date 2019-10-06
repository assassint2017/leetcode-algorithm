// 基本思路是使用二分查找

// Runtime: 148 ms, faster than 43.79% of C++ online submissions for Random Pick with Weight.
// Memory Usage: 32.9 MB, less than 40.00% of C++ online submissions for Random Pick with Weight.

class Solution 
{
public:
    Solution(vector<int>& w) 
    {
        for (int num : w)
        {
            sum += num;
            weights.push_back(sum);
        }
    }
    
    int pickIndex() 
    {
        int pos = random() % sum;
        
        int leftPtr = 0, rightPtr = weights.size() - 1;
        
        while (leftPtr < rightPtr)
        {
            int mid = (leftPtr + rightPtr) / 2;
            
            if (weights[mid] > pos) rightPtr = mid;
            else leftPtr = mid + 1;    
        }
    
        return leftPtr;
    }
private:
    int sum = 0;
    vector<int> weights;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */