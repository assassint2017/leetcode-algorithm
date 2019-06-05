// 目前没有想到什么比较好的解决方案，只能使用O(n2)的时间复杂度的算法

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate String.
// Memory Usage: 9.3 MB, less than 8.41% of C++ online submissions for Rotate String.

class Solution 
{
public:
    bool rotateString(string A, string B) 
    {
        // 边界条件处理
        if (A.length() != B.length())
            return false;
        if (A.length() == 0 && B.length() == 0)
            return true;
        
        for (int index = 0; index < A.length(); index++)
        {
            if (A.substr(index) + A.substr(0, index) == B)
                return true;
        }
        return false;
    }
};