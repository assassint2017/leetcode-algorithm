// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Two Sum II - Input array is sorted.
// Memory Usage: 9.6 MB, less than 100.00% of C++ online submissions for Two Sum II - Input array is sorted.

class Solution 
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> res;
        int leftPtr = 0, rightPtr = numbers.size() - 1;
        
        while (leftPtr < rightPtr)
        {
            int temp = numbers[leftPtr] + numbers[rightPtr];
            if (temp == target)
            {
                res.push_back(leftPtr + 1);
                res.push_back(rightPtr + 1);
                break;
            }
            else if (temp > target)
                rightPtr--;
            else 
                leftPtr++;
        }
        return res;
    }
};