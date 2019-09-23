// 使用递归的思想，附上大神的解题思路，是在是太NB了
// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/discuss/87768/4-lines-Python

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
// Memory Usage: 9.5 MB, less than 27.27% of C++ online submissions for Longest Substring with At Least K Repeating Characters.

class Solution
{
public:
	int longestSubstring(string s, int k)
	{
        // 递归停止条件
		if (k <= 0 || k > s.length())
			return 0;

		vector<int> hashmap(128, 0);
		for (char chr : s)
			++hashmap[chr];

		for (char chr = 'a'; chr <= 'z'; ++chr)
		{
			if (hashmap[chr] < k && hashmap[chr] > 0)
			{
				int res = 0;
				for (int leftPtr = 0, rightPtr = 0; leftPtr < s.length(); leftPtr = rightPtr + 1, rightPtr = leftPtr)
				{
					while (rightPtr < s.length() && s[rightPtr] != chr)
						++rightPtr;

					res = max(res, longestSubstring(s.substr(leftPtr, rightPtr - leftPtr), k));
				}

				return res;
			}
		}

		return s.length();
	}
};

// 下面是自己写的真n2的时间复杂度的，果然是非常的慢
// Runtime: 636 ms, faster than 5.05% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
// Memory Usage: 10.9 MB, less than 27.27% of C++ online submissions for Longest Substring with At Least K Repeating Characters.

class Solution 
{
public:
    int longestSubstring(string s, int target) 
    {
        int res = 0;
        for (int i = 0; i < s.length(); ++i)    
        {
            vector<int> hashmap(26, 0);
            for (int j = i; j < s.length(); ++j)
            {
                ++hashmap[s[j] - 'a'];
                
                bool ok = true;
                for (int k = 0; k < 26; ++k)
                {
                    if (hashmap[k] > 0 && hashmap[k] < target)
                    {
                        ok = false;
                        break;
                    }
                }
                
                if (ok) res = max(res, j - i + 1);
            }
        }
        return res;
    }
};