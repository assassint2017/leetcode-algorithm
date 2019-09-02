// Runtime: 8 ms, faster than 94.43% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 9.9 MB, less than 74.13% of C++ online submissions for Longest Substring Without Repeating Characters.

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int maxLength = 0;
        int rightPtr = s.length() - 1;
        
        vector<int> memo(128, -1);
        for (int leftPtr = s.length() - 1; leftPtr >= 0; --leftPtr)
        {
            if (memo[s[leftPtr]] != -1 && memo[s[leftPtr]] <= rightPtr)
                rightPtr = memo[s[leftPtr]] - 1;
            memo[s[leftPtr]] = leftPtr;
            maxLength = max(maxLength, rightPtr - leftPtr + 1);
        }
        
        return maxLength;
    }
};