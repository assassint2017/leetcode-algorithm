// Runtime: 16 ms, faster than 97.68% of C++ online submissions for Peak Index in a Mountain Array.
// Memory Usage: 9.6 MB, less than 13.82% of C++ online submissions for Peak Index in a Mountain Array.

class Solution 
{
public:
    int peakIndexInMountainArray(vector<int>& A) 
    {
        int leftPtr = 0, rightPtr = A.size() - 1;
        while (leftPtr < rightPtr)
        {
            int midPtr = (leftPtr + rightPtr) / 2;
            
            // 上升序列
            if (A[midPtr] < A[midPtr + 1] && A[midPtr] > A[midPtr - 1])
                leftPtr = midPtr + 1;
            // 下降序列
            else if (A[midPtr] > A[midPtr + 1] && A[midPtr] < A[midPtr - 1])
                rightPtr = midPtr - 1;
            // 刚好是峰值
            else
            {
                leftPtr = midPtr;
                break;
            }
        }
        
        if (A[leftPtr] > A[leftPtr + 1] && A[leftPtr] > A[leftPtr - 1])
            return leftPtr;
        else
            return rightPtr;
    }
};