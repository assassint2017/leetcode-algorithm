// Runtime: 8 ms, faster than 77.41% of C++ online submissions for Third Maximum Number.
// Memory Usage: 9.1 MB, less than 76.92% of C++ online submissions for Third Maximum Number.

class Solution 
{
public:
    int thirdMax(vector<int>& nums) 
    {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        bool found_INT_MIN = false;

        for (auto num : nums)
        {
            if (num == INT_MIN) found_INT_MIN = true;
            if (num == max1 || num == max2 || num <= max3) continue;

            if (num > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (num > max2)
            {
                max3 = max2;
                max2 = num;
            }
            else
                max3 = num;
        }

        if (max3 == INT_MIN)
        {
            if (found_INT_MIN && max2 != INT_MIN) return max3;
            else return max1;            
        }
        else
            return max3;
    }   
};