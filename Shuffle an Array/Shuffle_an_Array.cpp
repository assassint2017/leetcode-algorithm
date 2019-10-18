// 附参考链接 
// https://mp.weixin.qq.com/s/495KRYJwG0HQDiITY0Jqng

// Runtime: 196 ms, faster than 93.27% of C++ online submissions for Shuffle an Array.
// Memory Usage: 30.1 MB, less than 85.71% of C++ online submissions for Shuffle an Array.

class Solution 
{
public:
    Solution(vector<int>& nums) 
    {
        data = nums;
        size = data.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() 
    {
        return data;    
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() 
    {
        vector<int> shuffledata(data);
        
        for (int i = 0; i < size; ++i)
        {
            int pos = randint(i, size - 1);
            swap(shuffledata[i], shuffledata[pos]);
        }
        
        return shuffledata;
    }
private:
    inline int randint(int min, int max)
    {
        return min + rand() % (max - min + 1);
    }
private:
    vector<int> data;
    int size;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */