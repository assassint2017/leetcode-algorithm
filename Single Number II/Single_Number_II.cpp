// 同样，如果这道题目出现在面试中，应该考虑到各种边界条件
// 这道题目中的算法是可以扩展到N个重复数字的

// Runtime: 12 ms, faster than 93.36% of C++ online submissions for Single Number II.
// Memory Usage: 9.6 MB, less than 78.65% of C++ online submissions for Single Number II.

class Solution
{
public:
	int singleNumber(vector<int>& nums)
	{
		vector<int> memo(32, 0);
        
        long temp = 1;
		for (int index = 0; index < 32; index++, temp <<= 1)
		{
			for (auto number : nums)
			{
				memo[index] += ((temp & number) >= 1);
			}
			memo[index] %= 3;
		}

		int res = 0;
		for (int index = 31; index >= 0; index--)
		{
			res <<= 1;
			res += memo[index];
		}
		return res;
	}
};