// 完全不懂这道题目的意义所在 不过也应该算是一个双指针吧 

// Runtime: 56 ms, faster than 98.42% of C++ online submissions for Reverse String.
// Memory Usage: 17.9 MB, less than 28.51% of C++ online submissions for Reverse String.

class Solution 
{
public:
    void reverseString(vector<char>& s) 
    {
        for (int leftPtr = 0, rightPtr = s.size() - 1; leftPtr < rightPtr; leftPtr++, rightPtr--)
        {
            char temp = s[leftPtr];
            s[leftPtr] = s[rightPtr];
            s[rightPtr] = temp;
        }
    }
};  