// Runtime: 8 ms, faster than 77.55% of C++ online submissions for Next Permutation.
// Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Next Permutation.

class Solution 
{
public:
    void nextPermutation(vector<int>& nums) 
    {
        bool found = false;
        int k;
        for (k = nums.size() - 2; k >= 0; --k)
        {
            if (nums[k] < nums[k + 1])
            {
                found = true;
                break;
            }
        }
        
        if (found)
        {
            int i;
            for (i = nums.size() - 1; i > k; --i)
                if (nums[i] > nums[k])
                    break;
            
            swap(nums[i], nums[k]);
            reverse(nums.begin() + k + 1, nums.end());
        }
        else
            reverse(nums.begin(), nums.end());    
    }
};