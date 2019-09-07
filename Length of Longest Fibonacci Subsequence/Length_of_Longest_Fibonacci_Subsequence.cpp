// 第一种比较慢的思路
// Runtime: 292 ms, faster than 19.15% of C++ online submissions for Length of Longest Fibonacci Subsequence.
// Memory Usage: 9.5 MB, less than 85.71% of C++ online submissions for Length of Longest Fibonacci Subsequence.

class Solution 
{
public:
    int lenLongestFibSubseq(vector<int>& input) 
    {
        // 边界条件处理
        if (input.size() <= 2)
            return input.size();

        unordered_set<int> hashset(input.begin(), input.end());

        int maxLength = 0;
        for (int i = 0; i < input.size(); ++i)
        {
            for (int j = i + 1; j < input.size(); ++j)
            {
                int curLength = 2;

                int a = input[i];
                int b = input[j];

                while (hashset.find(a + b) != hashset.end())
                {
                    b = a + b;
                    a = b - a;
                    ++curLength;
                }
        
                maxLength = max(maxLength, curLength);
            }
        }
        return maxLength >= 3 ? maxLength : 0;
    }
};



// 第二种思路，使用动态规划进行加速 dp[i][j] 代表着以索引为i和j的元素为最后两位的斐波那契数列的最大长度
// Runtime: 252 ms, faster than 23.11% of C++ online submissions for Length of Longest Fibonacci Subsequence.
// Memory Usage: 62.4 MB, less than 14.29% of C++ online submissions for Length of Longest Fibonacci Subsequence.
class Solution
{
public:
	int lenLongestFibSubseq(vector<int>& input)
	{
		// 边界条件处理
		if (input.size() <= 2) return 0;

		int size = input.size();
		vector<vector<int>> dp(size, vector<int>(size, 2));
		unordered_map<int, int> hashmap;

		int maxLength = 0;
		for (int j = 0; j < input.size(); ++j)
		{
			hashmap.insert(pair<int, int>(input[j], j));
			for (int i = 0; i < j; ++i)
			{
				int a = input[i], b = input[j];

				if (hashmap.find(b - a) != hashmap.end() && hashmap.at(b - a) < i)
					dp[i][j] = max(dp[hashmap.at(b - a)][i] + 1, dp[i][j]);

				maxLength = max(maxLength, dp[i][j]);
			}
		}
		return maxLength >= 3 ? maxLength : 0;
	}
};