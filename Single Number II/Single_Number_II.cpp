// 这道题目剑指offer上应该是给错了，因为memo中存储的是数字的补码，不能直接转换为数字的!!!!!!
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
				memo[index] += ((temp & number) != 0);
			}
			memo[index] %= 3;
		}

		// 如果符号位为1，则需要将补码转换为原码
        if (memo[31] == 1)
        {
            bool found = false;
            for (int index = 0; index <= 30; index++)
            {
                if (memo[index] == 1)
                {
                    found = true;
                    memo[index] = 0;
                    while (--index >= 0)
                        memo[index] = 1;
                    break;
                }
            }
            if (!found)
                return INT_MIN;

            for (int i = 0; i <= 30; i++)
                memo[i] = (memo[i] == 0);
        }

		// 将补码转换为数字
		int res = 0;
		for (int index = 30; index >= 0; index--)
		{
			res <<= 1;
			res += memo[index];
		}
		return memo[31] == 0 ? res : -res;
	}
};
