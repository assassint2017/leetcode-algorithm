class Solution
{
public:
	vector<vector<int>> combinationSum3(int k, int n)
	{
		vector<vector<int>> res;
		vector<int> candidate;

		dfs(res, candidate, k, n, 1);

		return res;
	}
private:
	void dfs(vector<vector<int>>& res, vector<int>& candidate, int n, int target, int start)
	{
		if (n == 2)
		{
			int leftPtr = start;
			int rightPtr = 9;

			while (leftPtr < rightPtr)
			{
				if (leftPtr + rightPtr == target)
				{
					candidate.push_back(leftPtr);
					candidate.push_back(rightPtr);

					res.push_back(candidate);

					candidate.pop_back();
					candidate.pop_back();

					++leftPtr;
					--rightPtr;
				}
				else if (leftPtr + rightPtr > target)
				{
					--rightPtr;
				}
				else
				{
					++leftPtr;
				}
			}
		}
		else
		{
			for (int i = start; i <= 9; ++i)
			{
				candidate.push_back(i);

				dfs(res, candidate, n - 1, target - i, i + 1);

				candidate.pop_back();
			}
		}
	}
};