// Runtime: 24 ms, faster than 11.13% of C++ online submissions for Move Zeroes.
// Memory Usage: 9.5 MB, less than 75.00% of C++ online submissions for Move Zeroes.

class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        if (nums.empty()) return;
        
        int slowPtr = 0, fastPtr = 0;    
        
        while (fastPtr < nums.size())
        {
            while (fastPtr < nums.size() && nums[fastPtr] == 0) ++fastPtr;
            
            if (fastPtr >= nums.size()) break;
            
            nums[slowPtr++] = nums[fastPtr++];
        }
        
        while (slowPtr < nums.size())
        {
            nums[slowPtr++] = 0;
        }
    }
};