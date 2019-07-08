// 基本解题思路是使用哈希表

// Runtime: 256 ms, faster than 29.41% of C++ online submissions for Word Subsets.
// Memory Usage: 196.6 MB, less than 6.70% of C++ online submissions for Word Subsets.

class Solution
{
public:
	vector<string> wordSubsets(vector<string>& A, vector<string>& B)
	{
		vector<int> hashMap(128, 0);
		for (string str : B)
		{
			vector<int> temp(128, 0);
			for (char chr : str)
				temp[chr]++;

			for (int i = 'a'; i <= 'z'; i++)
				hashMap[i] = temp[i] > hashMap[i] ? temp[i] : hashMap[i];
		}

		vector<string> res;

		for (string str : A)
		{
			bool flag = true;

			vector<int> temp(128, 0);
			for (char chr : str)
				temp[chr]++;

			for (int i = 'a'; i < 'z'; i++)
			{
				if (hashMap[i] > temp[i])
				{
					flag = false;
					break;
				}
			}

			if (flag)
				res.push_back(str);
		}

		return res;
	}
};