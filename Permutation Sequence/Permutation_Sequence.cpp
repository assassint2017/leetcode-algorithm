// Runtime: 4 ms, faster than 69.49% of C++ online submissions for Permutation Sequence.
// Memory Usage: 8.1 MB, less than 98.28% of C++ online submissions for Permutation Sequence.

class Solution
{
public:
	string getPermutation(int n, int k)
	{
		string res = "";
		--k;

		vector<char> candidate(n);
		for (int i = 0; i < n; ++i)
			candidate[i] = i + 1;

		for (int i = 0; i < n - 1; ++i)
		{
			int fac = factorial(n - 1 - i);
			int index = k / fac;

			res += candidate[index] + '1' - 1;
			k %= fac;

			vector<char>::iterator iter = candidate.begin() + index;
			candidate.erase(iter);
		}
		res += candidate[0] + '1' - 1;
		return res;
	}
private:

	// 计算阶乘的小函数
	int factorial(int n)
	{
		int res = 1;
		for (int i = 1; i <= n; ++i)
			res *= i;
		return res;
	}
};